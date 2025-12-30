#include <iostream>
#include <vector>
#include <algorithm>
#include "PmergeMe.hpp"

#include <cstddef>

static void divideIntoPairs(
    const std::vector<int> &seq,
    std::vector< std::pair<int, int> > &pairs,
    bool &hasOdd,
    int &oddValue)
{
    pairs.clear();
    hasOdd = false;
    oddValue = 0;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        int a = seq[i];
        int b = seq[i + 1];
        if (a < b)
            std::swap(a, b);

        pairs.push_back(std::make_pair(a, b));
    }

    if (seq.size() % 2 != 0)
    {
        hasOdd = true;
        oddValue = seq.back();
    }
}

static size_t jacobsthal(size_t n)
{
    // J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    size_t j0 = 0;
    size_t j1 = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t j = j1 + 2 * j0;
        j0 = j1;
        j1 = j;
    }
    return j1;
}

static std::vector<size_t> buildJacobInsertionOrder(size_t pairCount)
{
    // We have pairCount losers to insert: b1..b_pairCount.
    // b1 is inserted first; then we insert indices in Jacobsthal batches:
    // b3,b2,b5,b4,b11,b10,b9,b8,b7,b6,... (1-based)
    std::vector<size_t> order;
    if (pairCount <= 1)
        return order;

    size_t prev = 1; // b1 already handled
    size_t k = 3;

    while (true)
    {
        size_t j = jacobsthal(k);
        if (j > pairCount)
            break;

        for (size_t b = j; b > prev; --b)
            order.push_back(b - 1); // convert 1-based b index to 0-based vector index

        prev = j;
        ++k;
    }

    for (size_t b = pairCount; b > prev; --b)
        order.push_back(b - 1);

    return order;
}

void printVector(const std::vector<int> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

static void boundedBinaryInsert(std::vector<int> &chain, int value, size_t boundInclusive)
{
    if (boundInclusive >= chain.size())
        boundInclusive = chain.size() - 1;

    std::vector<int>::iterator begin = chain.begin();
    std::vector<int>::iterator end = begin + (boundInclusive + 1);
    std::vector<int>::iterator pos = std::lower_bound(begin, end, value);
    chain.insert(pos, value);
}

bool cmp(const std::pair<int,int>& x, const std::pair<int,int>& y)
{
    return (x.first < y.first);
}

void ford_johnson_alg(std::vector<int> &seq)
{
    if (seq.size() <= 1)
        return;

    // 1) Pair input and normalize each pair so (winner >= loser)
    std::vector< std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddValue = 0;
    divideIntoPairs(seq, pairs, hasOdd, oddValue);

    // 2) Extract winners and recursively sort them -> this is the "main chain"
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
    ford_johnson_alg(winners);

    // 3) Rebuild pending losers aligned with the sorted winners (no std::map)
    // Build buckets grouped by winner using vectors.
    std::vector< std::pair<int, int> > sortedPairs = pairs;
    std::sort(sortedPairs.begin(), sortedPairs.end(), cmp);

    std::vector<int> uniqueWinners;
    std::vector< std::vector<int> > loserBuckets; // aligned with uniqueWinners

    for (size_t i = 0; i < sortedPairs.size(); ++i)
    {
        if (uniqueWinners.empty() || uniqueWinners.back() != sortedPairs[i].first)
        {
            uniqueWinners.push_back(sortedPairs[i].first);
            loserBuckets.push_back(std::vector<int>());
        }
        loserBuckets.back().push_back(sortedPairs[i].second);
    }

    std::vector<int> pending;
    for (size_t i = 0; i < winners.size(); ++i)
    {
        std::vector<int>::iterator it =
            std::lower_bound(uniqueWinners.begin(), uniqueWinners.end(), winners[i]);
        size_t idx = static_cast<size_t>(it - uniqueWinners.begin());

        // winners[i] must exist in uniqueWinners; pop one matching loser
        pending.push_back(loserBuckets[idx].back());
        loserBuckets[idx].pop_back();
    }

    // main chain starts as sorted winners
    std::vector<int> chain = winners;

    // 4) Insert losers using bounded binary insertion and Jacobsthal order
    if (!pending.empty())
    {
        // Insert b1 (loser paired with smallest winner) first
        size_t posWinner = static_cast<size_t>(
            std::lower_bound(chain.begin(), chain.end(), winners[0]) - chain.begin());
        boundedBinaryInsert(chain, pending[0], posWinner);

        // Insert the rest in Jacobsthal order
        std::vector<size_t> order = buildJacobInsertionOrder(pending.size());
        for (size_t k = 0; k < order.size(); ++k)
        {
            size_t idx = order[k];
            size_t posW = static_cast<size_t>(
                std::lower_bound(chain.begin(), chain.end(), winners[idx]) - chain.begin());
            boundedBinaryInsert(chain, pending[idx], posW);
        }
    }

    // 5) Insert odd leftover (if any)
    if (hasOdd)
        chain.insert(std::lower_bound(chain.begin(), chain.end(), oddValue), oddValue);

    seq.swap(chain);
}

int main()
{
    std::vector<int> input;
    int arr[] = {11, 2, 17, 0, 16, 6, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};

    for (int i = 0; i < 22; i++)
        input.push_back(arr[i]);

    std::cout << "Before: ";
    printVector(input);
    ford_johnson_alg(input);
    std::cout << "After : ";
    printVector(input);
    return 0;
}

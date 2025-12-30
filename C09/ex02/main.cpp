#include <iostream>
#include <vector>
#include <algorithm>
#include "PmergeMe.hpp"

#include <cstddef>

static void div2Pairs(
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
        if (seq[i] > seq[i+1])
            pairs.push_back(std::make_pair(seq[i], seq[i+1]));
        else
            pairs.push_back(std::make_pair(seq[i+1], seq[i]));
    }

    if (seq.size() % 2 != 0)buildJacobInsertionOrder
    {
        hasOdd = true;
        oddValue = seq.back();
        // oddValue = seq[seq.size()-1];
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
    div2Pairs(seq, pairs, hasOdd, oddValue);

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
/*
*What this program is
This workspace implements a Ford–Johnson / merge-insertion sort variant for a std::vector<int> and demonstrates it on a fixed array. The main algorithm is in ford_johnson_alg in main.cpp. The header PmergeMe.hpp only defines ANSI color macros and isn’t used by the algorithm.

File overview
PmergeMe.hpp
Defines color escape sequences (RED, GREEN, …). No classes/functions.

main.cpp
Contains helper functions plus the sorting routine and a demo main().

Core idea (Ford–Johnson / merge-insertion sort)
Given a sequence:

Split into pairs (a, b).
Within each pair, ensure a >= b (so a is the “winner”, b the “loser”).
Recursively sort the list of winners → this becomes the main chain.
Insert the losers into the main chain using binary search, but with a bounded search range (each loser is only searched up to the position of its paired winner).
The order of inserting losers is chosen using Jacobsthal numbers to reduce comparisons.
Functions, explained
1) Pairing and normalization
divideIntoPairs

Inputs: the original sequence seq.
Outputs:
pairs: vector of (winner, loser) pairs.
hasOdd / oddValue: if the input length is odd, the last element is saved separately.
Logic:
Walks seq two at a time.
For each pair (seq[i], seq[i+1]), it swaps so the first is larger: winner >= loser.
If there is an unpaired last element, it becomes oddValue.
2) Jacobsthal numbers (for insertion schedule)
jacobsthal

Computes Jacobsthal numbers iteratively using:

J(0)=0,J(1)=1,J(n)=J(n−1)+2J(n−2)
Used only to generate the “best” order to insert losers.
buildJacobInsertionOrder

Builds an index order for inserting losers (except the first loser, which is handled separately).
Comment in code describes the intended 1-based loser order pattern (e.g., b3,b2,b5,b4,...).
Returns 0-based indices into the pending losers array.
3) Printing helper
printVector

Prints the vector as [a, b, c].
4) Bounded binary insertion
boundedBinaryInsert

Inserts value into sorted vector chain, but only searches in the range:
chain.begin() to chain.begin() + (boundInclusive + 1)
Uses std::lower_bound to find insertion position, then vector::insert.
Purpose: in Ford–Johnson, a loser b_i is guaranteed to be 
≤
≤ its winner a_i, so it never needs to be inserted after the winner’s position.
5) Pair comparator
cmp

Compares pairs by .first (the winner), used for sorting the original pairs by winner.
The main algorithm
ford_johnson_alg

Base case
If seq.size() <= 1, already sorted.
Step 1: Build normalized pairs
Calls [divideIntoPairs[](main.cpp) → produces ](http://_vscodecontentref_/35)(winner, loser) pairs + possible odd leftover.
Step 2: Sort winners recursively
Extract all winners into winners.
Recursively calls [ford_johnson_alg[](main.cpp) on ](http://_vscodecontentref_/37)winners.
After this, winners is sorted: this becomes the initial main chain.
Step 3: Align losers to the sorted winners (without std::map)
Because recursion sorted winners, you need the losers in the same order as their corresponding winners in the sorted winners list.

The code does:

Copy pairs into sortedPairs.
Sort sortedPairs by winner using cmp.
Build:
uniqueWinners: each distinct winner value once
loserBuckets: parallel vector of vectors; each bucket holds all losers for that winner (handles duplicate winners)
Then for each winner in winners:

Find its winner value in uniqueWinners using lower_bound
Pop one loser from the corresponding bucket and push it into pending
Result: pending[i] is the loser paired with winners[i] in the same winner order.

Step 4: Insert losers into the chain
Start: chain = winners (already sorted)
Insert the first pending loser (pending[0]) first:
Find winners[0] position in chain
Insert loser using boundedBinaryInsert up to that position
Build the Jacobsthal-based insertion order using buildJacobInsertionOrder
For each remaining loser index idx in that order:
Compute the current position of winners[idx] in chain
Insert pending[idx] bounded up to that position
Step 5: Insert odd leftover
If the original input had an odd last element, insert it into the fully built chain using lower_bound over the whole chain.
Finally:

seq.swap(chain) replaces the input with the sorted result.
main() demonstration
main

Builds a std::vector<int> from a fixed array of 22 ints.
Prints “Before”, runs ford_johnson_alg, prints “After”.
Notes / behavior details
Handles duplicates (e.g., there are two 6 values in the sample input) via the “bucket per winner value” approach.
Correctness relies on winners being sorted and each loser being inserted no later than its paired winner position.
Performance: uses many vector::insert operations, which are 
𝑂
(
𝑛
)
O(n) shifts each; comparison count may be optimized by Jacobsthal ordering, but data movement is still vector-based.

*/
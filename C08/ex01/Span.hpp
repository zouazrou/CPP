/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:21:34 by zouazrou          #+#    #+#             */
/*   Updated: 2025/12/15 09:22:36 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <stdexcept>
# include <climits>
# include <iterator>
# include <cmath>

class Span
{
private:
    size_t              N;
    std::multiset<int>  myContainer;
public:
    Span(size_t N);
    Span(const Span& othr);
    Span&   operator= (const Span& othr);
    ~Span();

    void    addNumber(int num);
    int     shortestSpan(void);
    int     longestSpan(void);

    template    <typename it>
    void    addNumber(it begin, it end)
    {
        long lenSq = abs(std::distance(begin, end));

        if (myContainer.size() + lenSq > N)
            throw std::runtime_error("size is not enough for this numbers");
        myContainer.insert(begin, end);
    }

};

#endif
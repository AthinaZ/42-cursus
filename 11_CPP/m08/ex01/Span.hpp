/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:19:36 by azouzoul          #+#    #+#             */
/*   Updated: 2022/02/01 16:01:47 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <list>


class Span
{
	private:
		unsigned int _N;
		unsigned int _numsStored;
		std::vector<int> _vector;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &op);
		~Span();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();

		class OutOfRangeException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("Out of range");
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				const char * what() const throw()
				{
					return ("No span found");
				}
		};

		template <typename iter>
		void addNumber(iter begin, iter end)
		{
			int remaining;

			remaining= _N - _numsStored;
			if (remaining <= 0 || std::distance(begin, end) > remaining)
				throw Span::OutOfRangeException();
			_vector.insert(_vector.begin(), begin, end);
			_numsStored += std::distance(begin, end);
		}

		unsigned int getSize(void) const;
		unsigned int getNumsStored(void) const;
		unsigned int getRemaining(void) const;
		std::vector<int>	getVector(void) const;
};

std::ostream &operator << (std::ostream &out, Span const &span);

#endif

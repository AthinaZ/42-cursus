/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:17:16 by azouzoul          #+#    #+#             */
/*   Updated: 2022/02/01 16:04:55 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _numsStored(0) {}

Span::Span(unsigned int N) : _N(N), _numsStored(0) {}

Span::Span(const Span &copy) :
_N(copy._N), _numsStored(copy._numsStored), _vector(copy._vector) {}

Span &Span::operator=(const Span &op)
{
	_N = op._N;
	_numsStored = op._numsStored;
	_vector = op._vector;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (this->_numsStored >= _N)
		throw Span::OutOfRangeException();
	_vector.push_back(num);
	_numsStored++;
}

int Span::shortestSpan()
{
	if (_numsStored <= 1)
		throw Span::NoSpanException();

	int shortestSpan = longestSpan();
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	for (unsigned int i = 0; i < _numsStored; i++)
	{
			if (std::abs(copy[i + 1] - copy[i]) < shortestSpan)
			shortestSpan = std::abs(copy[i + 1] - copy[i]);
	}
	return (shortestSpan);
}

int Span::longestSpan()
{
	int	min;
	int	max;

	if (_numsStored <= 1)
		throw Span::NoSpanException();
	min = *std::min_element(_vector.begin(),_vector.end());
	max = *std::max_element(_vector.begin(),_vector.end());

	if (min == max)
		throw Span::NoSpanException();
	return max - min;
}

unsigned int Span::getSize(void) const
{
	return (_N);
}

unsigned int Span::getNumsStored(void) const
{
	return (_numsStored);
}

unsigned int Span::getRemaining(void) const
{
	return (_N - _numsStored);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

std::ostream &operator << (std::ostream &out, Span const &span)
{
	for (unsigned int i = 0; i < span.getNumsStored(); i++)
		std::cout << span.getVector()[i] << " ";
	std::cout << std::endl;
	return (out);
}

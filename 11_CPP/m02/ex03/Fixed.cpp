/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:28:04 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:28:06 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_pt_value = 0;
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}


Fixed::Fixed(const int nb)
{
	this->fixed_pt_value = nb << this->fractional_bits;
}

Fixed::Fixed(const float flt)
{
	this->fixed_pt_value = roundf(flt * (1 << this->fractional_bits));
}

int Fixed::getRawBits(void) const
{
	return this->fixed_pt_value;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_pt_value = raw;
}

int Fixed::toInt(void) const
{
	return ((int)this->fixed_pt_value >> this->fractional_bits);
	//return (roundf(this->toFloat()));
}

float Fixed::toFloat() const
{
	return ((float)this->fixed_pt_value / (float)(1 << this->fractional_bits));
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	this->fixed_pt_value = fixed.fixed_pt_value;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	if (this->fixed_pt_value > fixed.fixed_pt_value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	if (this->fixed_pt_value < fixed.fixed_pt_value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	if (this->fixed_pt_value >= fixed.fixed_pt_value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	if (this->fixed_pt_value <= fixed.fixed_pt_value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	if (this->fixed_pt_value == fixed.fixed_pt_value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	if (this->fixed_pt_value != fixed.fixed_pt_value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed new_fixed;
	new_fixed.fixed_pt_value = this->fixed_pt_value + fixed.fixed_pt_value;
	return new_fixed;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed new_fixed;
	new_fixed.fixed_pt_value = this->fixed_pt_value - fixed.fixed_pt_value;
	return new_fixed;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed new_fixed;
	new_fixed.fixed_pt_value = (this->fixed_pt_value * fixed.fixed_pt_value) / (1 << this->fractional_bits);
	return new_fixed;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed new_fixed;
	new_fixed.fixed_pt_value = (this->fixed_pt_value * (1 << this->fractional_bits)) / fixed.fixed_pt_value;
	return new_fixed;
}

Fixed &Fixed::operator++()
{
	this->fixed_pt_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed new_fixed;
	new_fixed = *this;
	++*this;
	return new_fixed;
}

Fixed &Fixed::operator--()
{
	this->fixed_pt_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	//Fixed new_fixed;
	Fixed new_fixed = *this;
	--*this;
	return new_fixed;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	else
		return b;
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

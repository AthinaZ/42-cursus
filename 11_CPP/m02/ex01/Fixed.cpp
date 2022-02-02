/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:38:38 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 19:38:39 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed_pt_value(0)
{
	std::cout <<"Default contrustor called" << std::endl;
	//this->fixed_pt_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_pt_value = nb << this->fractional_bits;
}

Fixed::Fixed(const float flt)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_pt_value = roundf(flt *(1 << this->fractional_bits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_pt_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_pt_value = raw;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_pt_value = fixed.fixed_pt_value;
	return *this;
}

int Fixed::toInt(void) const
{
	return ((int)this->fixed_pt_value >> this->fractional_bits);
	//return(roundf(this->toFloat()));
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixed_pt_value / (float)(1 << this->fractional_bits));
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return out;
}

//https://stackoverflow.com/questions/79677/whats-the-best-way-to-do-fixed-point-math

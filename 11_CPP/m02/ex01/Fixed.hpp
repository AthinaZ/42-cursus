/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:38:50 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 19:38:52 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_pt_value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int nb);
		Fixed(const float flt);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator = (Fixed const &fixed);
		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif


// convert an int or float to it corresponding fixed point value
// see: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/

// converting from fixed-point to floating-point:
// take the input value and divide it by (2^fractional_bits) and put result into float

// convert from floating-point to fixed-point:
// Calculate fixed_point = floating_input * 2^(fractional_bits)
// Round fixed_point to the nearest whole number (using e.g. roundf)
// Store the rounded fixed_point in const float

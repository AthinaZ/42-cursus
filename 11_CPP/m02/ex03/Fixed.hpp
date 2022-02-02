/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:28:21 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:28:22 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
		void setRawBits(const int raw);
		//void setRawBits(const float raw);

		Fixed &operator=(Fixed const &fixed);
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed &operator++(); //Prefix increment
		Fixed operator++(int); //Postfix increment
		Fixed &operator--(); // pre-decrement;
		Fixed operator--(int); // post-decrement;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);

		int toInt(void) const;
		float toFloat() const;

};

	std::ostream &operator << (std::ostream &out, const Fixed &fixed);

# endif

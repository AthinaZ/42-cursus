/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:22:38 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:22:39 by azouzoul         ###   ########.fr       */
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
		Fixed &operator++(); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed &operator--(); // pre-decrement;
		Fixed operator--(int); // post-decrement;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);

		int toInt(void) const;
		float toFloat(void) const;

};

	std::ostream &operator << (std::ostream &out, const Fixed &fixed);

# endif

// see: https://www.learncpp.com/cpp-tutorial/overloading-the-increment-and-decrement-operators/#:~:text=The%20difference%20between%20the%20two,has%20been%20incremented%20or%20decremented.&text=The%20postfix%20operators%2C%20on%20the,it%20is%20incremented%20or%20decremented.

// c++ specs for post-increment and post-decrement: overload operator needs an int parameter
// c++ specs for pre-increment and pre-decrement: overload operator DOES NOT HAVE an int parameter
// pre : We return by reference so you can chain multiple operators together in the same expression. Otherwise the second evaluated operator would be applied to the returned copy, not the original object.

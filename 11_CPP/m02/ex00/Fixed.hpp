/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:19:26 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 17:19:28 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed_pt_value;
		static const int fractional_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator = (Fixed const &fixed);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:22:11 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:22:12 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	// Fixed const c(Fixed(5.05f) / Fixed(2));
	// Fixed const d(Fixed(5.05f) + Fixed(2));
	// Fixed const e(Fixed(5.05f) - Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << e << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	//std::cout << Fixed::min(a, b) << std::endl;

	return (0);

}

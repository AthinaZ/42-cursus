/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 21:13:05 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << BLUE << "WrongCat -- Constructor called" << OFF << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << BLUE << "WrongCat -- Destructor called" << OFF << std::endl;
}

WrongCat::WrongCat(const WrongCat &wc)
{
	std::cout << BLUE << "WrongCat -- Copy constructor called" << OFF << std::endl;
	*this = wc;
}

void	WrongCat::makeSound() const
{
	std::cout << this->type << " : " << "MEOW MEOW will never output" << std::endl;
}

WrongCat &WrongCat::operator= (const WrongCat &obj)
{
	std::cout << YEL << "WrongCat -- Assignment operator called" << OFF << std::endl;
	this->type = obj.type;
	return *this;
}

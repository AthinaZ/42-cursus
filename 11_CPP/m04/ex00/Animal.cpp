/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 13:57:33 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::makeSound() const
{
	std::cout << this->getType() << " : " <<  "UNDEFINED SOUND" << std::endl;
}

Animal::Animal()
{
	std::cout << BLUE << "Animal -- Constructor called" << OFF << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal -- Destructor called" << OFF << std::endl;
}

Animal::Animal (const Animal &copy)
{
	std::cout << BLUE << "Animal -- Copy constructor called" << OFF << std::endl;
	*this = copy;
}

Animal &Animal::operator= (const Animal &obj)
{
	std::cout << BLUE << "Animal -- Assignment operator called" << OFF << std::endl;
	this->type = obj.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

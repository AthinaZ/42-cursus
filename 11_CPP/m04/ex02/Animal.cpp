/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/23 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::makeSound() const
{
	std::cout << this->getType() << " : " <<  "UNDEFINED SOUND" << std::endl;
}

Animal::Animal()
{
	std::cout << BLUE << "Animal -- Default constructor called" << OFF << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal -- Destructor called" << OFF << std::endl;
}

Animal::Animal (const Animal& animal)
{
	std::cout << BLUE << "Animal -- Copy constructor called" << OFF << std::endl;
	this->type = animal.getType();
}

void Animal::operator= (const Animal& assign)
{
	std::cout << BLUE << "Animal -- Assignment operator called" << OFF << std::endl;
	this->type = assign.type;
}

std::string Animal::getType() const
{
	return this->type;
}

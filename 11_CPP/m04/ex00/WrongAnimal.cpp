/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 14:10:59 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::makeSound() const
{
	std::cout << this->type << " : " <<  "UNDEFINED SOUND" << std::endl;
}

WrongAnimal::WrongAnimal()
{
	std::cout << BLUE << "WrongAnimal -- Constructor called" << OFF << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE << "WrongAnimal -- Destructor called" << OFF << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal &obj)
{
	std::cout << YEL << "WrongAnimal -- Assignment operator called" << OFF << std::endl;
	this->type = obj.type;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	std::cout << BLUE << "WrongAnimal -- Copy constructor called" << OFF << std::endl;
	*this = wa;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

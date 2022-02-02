/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 21:10:08 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << BLUE << "Dog -- Constructor called" << OFF << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &dog)
{
	std::cout << BLUE << "Dog -- Copy constructor called" << OFF << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << YEL << "Dog -- Assignment operator called" << OFF << std::endl;
	this->type = dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog -- Destructor called" << OFF << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << " : WOOF" << std::endl;
}

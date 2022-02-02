/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 21:23:36 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << BLUE << "Dog -- Default constructor called" << OFF << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << BLUE << "Dog -- Copy constructor called" << OFF << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << YEL << "Dog -- Assignment operator called" << OFF << std::endl;
	this->type = dog.getType();
	*brain = *dog.brain;
	return *this;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog -- Destructor called" << OFF << std::endl;
	delete(brain);
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << " : WOOF" << std::endl;
}

void	Dog::setIdea(const std::string &idea)
{
	this->brain->setIdea(idea);
}

std::string Dog::getIdea(void) const
{
	return (this->brain->getIdea());
}

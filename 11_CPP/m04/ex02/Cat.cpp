/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 21:22:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << BLUE << "Cat -- Default constructor called" << OFF << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << YEL << "Cat -- Assignment operator called" << OFF << std::endl;
	this->type = cat.getType();
	*brain = *cat.brain;
	return *this;
}

Cat::Cat(const Cat &cat)
{
	std::cout << BLUE << "Cat -- Copy constructor called" << OFF << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat::~Cat ()
{
	std::cout << BLUE << "Cat -- Destructor called" << OFF << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << " : MEOW" << std::endl;
}

void	Cat::setIdea(const std::string &idea)
{
	this->brain->setIdea(idea);
}

std::string Cat::getIdea(void) const
{
	return (this->brain->getIdea());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 13:57:43 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << BLUE << "Cat -- Constructor called" << OFF << std::endl;
	this->type = "Cat";
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << YEL << "Cat -- Assignment operator called" << OFF << std::endl;
	this->type = cat.type;
	return *this;
}

Cat::Cat(const Cat &cat)
{
	std::cout << BLUE << "Cat -- Copy Constructor called" << OFF << std::endl;
	*this = cat;
}

Cat::~Cat ()
{
	std::cout << BLUE << "Cat -- Destructor called" << OFF << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << " : MEOW" << std::endl;
}

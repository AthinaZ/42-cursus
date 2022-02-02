/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/23 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Brain -- Default constructor called" << OFF << std::endl;
}

Brain::~Brain()
{
	std::cout << BLUE << "Brain -- Destructor called" << OFF << std::endl;
}

Brain & Brain::operator=(const Brain &brain)
{
	std::cout << YEL << "Brain -- Assignment operator called" << OFF << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return *this;
}

Brain::Brain(const Brain &brain)
{
	std::cout << BLUE << "Brain -- Copy constructor called" << OFF << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

void	Brain::setIdea(const std::string &idea)
{
	this->ideas[0] = idea;
}

std::string Brain::getIdea(void) const
{
	return this->ideas[0];
}

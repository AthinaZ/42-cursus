/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:51:28 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 16:15:43 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() 
{
	this->type = "cure";
}

Cure::Cure(std::string const &type)
{
	this->type = type;
}

Cure::~Cure()
{
	
}

Cure::Cure(Cure const &obj)
{
	*this = obj;
}

Cure &Cure::operator = (Cure const &obj)
{
	this->type = obj.type;
	return *this;
}

Cure* Cure::clone() const
{
	Cure *ret = new Cure(*this);
	return ret;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

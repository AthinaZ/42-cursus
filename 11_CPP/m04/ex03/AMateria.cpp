/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:49:59 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 22:30:45 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
	
}

AMateria::AMateria(std::string const &type) : type(type)
{

}

AMateria::AMateria(AMateria const &obj)
{
	*this = obj;
}

AMateria &AMateria::operator = (AMateria const &obj)
{
	this->type = obj.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	//std::cout << "AMateria->use: " << target.getName() << std::endl;
	(void)target;
}

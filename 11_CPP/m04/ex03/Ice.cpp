/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:52:01 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 16:15:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::~Ice()
{
	
}

Ice::Ice(std::string const & type)
{
	this->type = type;
}

Ice::Ice(Ice const &obj)
{
	*this = obj;
}

Ice &Ice::operator=(Ice const &obj)
{
	this->type = obj.type;
	return *this;
}

Ice *Ice::clone() const
{
	Ice *ret = new Ice(*this);
	return ret;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

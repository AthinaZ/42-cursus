/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:22:04 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/23 16:22:05 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type)
{

}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}

const std::string Weapon::getType() const
{
	return (this->type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:23:02 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/23 16:23:04 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string const &name): weapon(NULL), name(name)
{

}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " does not have a weapon " << std::endl;

}

void HumanB::setWeapon(Weapon &weapon_type)
{
	this->weapon = &weapon_type;
}


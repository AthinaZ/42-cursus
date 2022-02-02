/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:34:37 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:39 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << MAG << "ScavTrap - Default construct called." << OFF << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->name = "Default";
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << MAG << "ScavTrap - Copy construct called." << OFF << std::endl;
	*this = copy;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << MAG << "ScavTrap - " << "<" << this->name << ">" << " constructor called." << OFF << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << MAG << "ScavTrap - Destructor called." << OFF << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << YEL << "ScavTrap - Assignation operator called" << OFF << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap - " << "<" << this->name << ">" << " attacks " << "<" << target << ">" << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap - " << "<" << this->name << ">" << " entered in Gate keeper mode." << std::endl;
}

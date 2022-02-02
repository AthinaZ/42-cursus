/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:32:34 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:32:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << BLUE << "ClapTrap - Default constructor called." << OFF << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << BLUE << "ClapTrap - Copy constructor called." << OFF << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << YEL << "ClapTrap - Assignation operator called" << OFF << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << BLUE << "ClapTrap - " << "<" << this->name << ">" << " constructor called." << OFF << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE << "ClapTrap - Destructor called." << OFF << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap - " << "<" << this->name << ">" << " attacking " << "<" << target << ">" << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap - " << "<" << this->name << ">" << " took " << amount << " points of damage!" << std::endl;
	energyPoints -= amount;
	std::cout << "ClapTrap - " << "<" << this->name << ">" << " has " << this->energyPoints << " energy points remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap - " << "<" << this->name << ">" << " repaired by " << amount << " points of damage!" << std::endl;
	energyPoints += amount;
	std::cout << "ClapTrap - " << "<" << this->name << ">" << " has " << this->energyPoints << " energy points remaining." << std::endl;
}

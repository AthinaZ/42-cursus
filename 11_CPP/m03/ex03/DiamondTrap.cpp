/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << CYN << "DiamondTrap - Default construct called." << OFF << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	*this = copy;
	std::cout << CYN << "DiamondTrap - Copy construct called." << OFF << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	// this->hitPoints = FragTrap::hitPoints; //100
	// this->energyPoints = ScavTrap::energyPoints; //50
	// this->attackDamage = FragTrap::attackDamage; //30
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	std::cout << CYN << "DiamondTrap - " << "<" << this->name << ">" << " constructor called." << OFF << std::endl;
	std::cout << "hitpoints: " << hitPoints << " | energy points: " << energyPoints << " | attack damage: " << attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << CYN << "DiamondTrap - Destructor called." << OFF << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << YEL << "DiamondTrap - Assignation operator called" << OFF << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap - Who Am I ... Diamond name: " << "<" << this->name << ">" << " Clap name: " << "<" << ClapTrap::name << ">" << "." << std::endl;
}

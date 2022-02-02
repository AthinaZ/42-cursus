/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GRN << "FragTrap    - Default construct called." << OFF << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << GRN << "FragTrap - Copy construct called." << OFF << std::endl;
	*this = copy;
}

FragTrap::FragTrap(const std::string &name) //: ClapTrap(name)
{
	std::cout << GRN << "FragTrap    - " << "<" << this->name << ">" << " constructor called." << OFF << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << GRN << "FragTrap    - Destructor called." << OFF << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << GRN << "FragTrap - Assignation operator called." << OFF << std::endl;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap - " << "<" << this->name << ">" << " attacks " << "<" << target << ">" << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap    - " << "<" << this->name << ">" << " is asking others for a highfive!" << std::endl;
}

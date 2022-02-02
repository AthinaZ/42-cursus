/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:20:12 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/23 13:20:14 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string ZombieName)
{
	this->name = ZombieName;
	std::cout << this->name << " zombies were created :) - Constructor called" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;

}

void	Zombie::setName(std::string name)
{
	this->name = name;

}

Zombie::~Zombie()
{
	std::cout << this->name << " zombie was destroyed :( - Destructor called" << std::endl;
}

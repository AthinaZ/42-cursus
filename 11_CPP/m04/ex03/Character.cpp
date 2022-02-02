/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:51:06 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 16:15:31 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	
}

Character::Character(Character const &obj)
{
	*this = obj;
	this->name = obj.getName();
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
	}
}

Character & Character::operator = (Character const &obj)
{
	this->name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		if (obj.materia[i])
			this->materia[i] = obj.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	int i = -1;
	while (++i < 4)
		if (!this->materia[i])
		{
			this->materia[i] = m;
			break;
		}
}

void Character::unequip(int idx)
{
	this->materia[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	this->materia[idx]->use(target);
}

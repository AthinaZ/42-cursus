/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:53:10 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/15 22:38:17 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.materia[i])
			this->materia[i] = obj.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->materia[i];
}


MateriaSource &MateriaSource::operator = (MateriaSource const &obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.materia[i])
			this->materia[i] = obj.materia[i]->clone();
		else
			this->materia[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && type == this->materia[i]->getType())
			return this->materia[i]->clone();
	}
	return NULL;
}

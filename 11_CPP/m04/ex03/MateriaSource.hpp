/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:53:24 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 16:15:29 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &obj);
		~MateriaSource();

		MateriaSource &operator = (MateriaSource const &obj);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
	protected:
		AMateria *materia[4];
};

#endif


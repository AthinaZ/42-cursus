/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 15:21:02 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

# define	BLUE		"\033[0;34m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"


class	Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal (const Animal &copy);
		Animal &operator= (const Animal &obj);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};

#endif

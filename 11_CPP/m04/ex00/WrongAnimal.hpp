/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 14:06:27 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

# define	BLUE		"\033[0;34m"
# define 	YEL			"\e[0;33m"
# define	OFF			"\033[0m"

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wa);
		virtual ~WrongAnimal(); // if this is not virtual WrongCat destructor not called
		WrongAnimal &operator= (const WrongAnimal &obj);
		std::string getType() const;
		void	makeSound() const;
	protected:
		std::string type;
};

#endif

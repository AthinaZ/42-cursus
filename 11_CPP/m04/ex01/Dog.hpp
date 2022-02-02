/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 15:08:34 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog &operator=(const Dog &dog);
		Dog(const Dog &dog);
		void makeSound() const;
		void setIdea(const std::string &idea);
		std::string getIdea() const;
	private:
		Brain *brain;
};

#endif

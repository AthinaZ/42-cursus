/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/12/16 15:15:39 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal *animals[6];
	Cat tabby;
	Dog fido;
	//Animal bear; // won't compile because abstract class
	
	tabby.setIdea("PURR");
	Cat kitty(tabby);
	fido.setIdea("HOWL");
	Dog puppy(fido);
	
	for (int y = 0; y < 6; y++)
	{
		if (y % 2 == 0)
			animals[y] = new Dog();
		else
			animals[y] = new Cat();
	}
	for(int y = 0; y < 6; y++)
	{
		animals[y]->makeSound();
	}

	//bear.makeSound(); // Animal is abstract class now so won't work!!

	std::cout << "\nCat Class - SHOW THAT COPIES ARE DEEP:" << std::endl;
	std::cout << "Set idea:" << std::endl;
	std::cout << "\tTabby: " << tabby.getIdea() << std::endl;
	std::cout << "\tKitty: " << kitty.getIdea() << std::endl;
	tabby.setIdea("HISS");
	std::cout << "Set new idea:" << std::endl;
	std::cout << "\tTabby: " << tabby.getIdea() << std::endl;
	std::cout << "\tKitty: " << kitty.getIdea() << std::endl;

	std::cout << "Dog Class - SHOW THAT COPIES ARE DEEP:" << std::endl;
	std::cout << "Set idea:" << std::endl;
	std::cout << "\tFido: " << fido.getIdea() << std::endl;
	std::cout << "\tPuppy: " << puppy.getIdea() << std::endl;
	fido.setIdea("GROWL");
	std::cout << "Set new idea:" << std::endl;
	std::cout << "\tFido: " << fido.getIdea() << std::endl;
	std::cout << "\tPuppy: " << puppy.getIdea() << std::endl;
	delete j;
	delete i;
	for (int y = 0; y < 6; y++)
		delete animals[y];
}

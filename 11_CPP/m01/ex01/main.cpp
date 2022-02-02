/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:20:02 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/23 13:20:04 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	annnouceHorde(Zombie *ZombieHorde, int nbOfZombies)
{
	for (int i = 0; i < nbOfZombies; i++)
		ZombieHorde[i].announce();
}

int main(void)
{
	std::cout << "Creating a zombie horde of Bob's" << std::endl;
	{

		Zombie *aZombieHorde = ZombieHorde(5, "Bob");
		annnouceHorde(aZombieHorde, 5);
		delete [] aZombieHorde;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:11:23 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 18:11:25 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	Zombie zombie("Rob"); //stack
	zombie.annouce();

	Zombie *newZombieCreate = newZombie("Clarissa"); //heap
	newZombieCreate->annouce();
	delete newZombieCreate;

	randomChump("George");

	return (0);
}

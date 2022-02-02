/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:58 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:00 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap def;
	FragTrap bob("Bobby");
	FragTrap copy(bob);
	FragTrap tom("Tommy");

	tom = bob;

	tom.attack("Jimmy");
	bob.attack("Bobby");
	tom.beRepaired(10);
	tom.takeDamage(20);
	tom.highFivesGuys();

	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:34:24 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:34:25 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

	ScavTrap def;
	ScavTrap bob("Bobby");
	ScavTrap copy(bob);
	ScavTrap tom("Tommy");

	tom = bob;

	tom.attack("Timmy");
	bob.attack("Sammy");
	tom.beRepaired(10);
	tom.takeDamage(20);
	tom.guardGate();

	return (0);
}




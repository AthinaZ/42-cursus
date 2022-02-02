/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:33:02 by azouzoul          #+#    #+#             */
/*   Updated: 2021/10/03 23:33:03 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap def;
	ClapTrap bob("Bobby");
	ClapTrap copy(bob);
	ClapTrap tom("Tommy");

	tom = bob;

	tom.attack("Timmy");
	bob.attack("Sammy");
	tom.beRepaired(10);
	tom.takeDamage(20);

	return (0);
}

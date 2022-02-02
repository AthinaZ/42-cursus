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

#include "DiamondTrap.hpp"

int main()
{
	
	DiamondTrap def;
	DiamondTrap tom("Tommy");
	//DiamondTrap copy(tom);

	//def = tom;
	
	tom.attack("Jimmy");
	tom.beRepaired(10);
	tom.takeDamage(20);
	tom.guardGate();
	tom.highFivesGuys();
	tom.whoAmI();

	return (0);
}

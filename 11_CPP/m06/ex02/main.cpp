/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:16:49 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:16:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
	std::srand(std::time(0)); // need to call this before calling std::rand()

	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "GENERATING RANDOM BASE CHILDREN:" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	Base *rand1 = generate();
	Base *rand2 = generate();
	Base *rand3 = generate();
	Base *rand4 = generate();
	std::cout << std::endl;

	// Create references
	Base &rand1_ref = *rand1; 
	Base &rand2_ref = *rand2;
	Base &rand3_ref = *rand3;
	Base &rand4_ref = *rand4;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "IDENTIFY VIA ADDRESS:" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	pidentify(rand1);
	pidentify(rand2);
	pidentify(rand3);
	pidentify(rand4);
	std::cout << std::endl;

	std::cout << "--------------------------------" << std::endl;
	std::cout << "IDENTIFY VIA REFERENCE:" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	ridentify(rand1_ref);
	ridentify(rand2_ref);
	ridentify(rand3_ref);
	ridentify(rand4_ref);
	std::cout << std::endl;

	delete rand1;
	delete rand2;
	delete rand3;
	delete rand4;
	std::cout << std::endl;
	return (0);
}

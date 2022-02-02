/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:53 by azouzoul          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:59 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int createIntVector()
{
	int intGenerator = rand() % 20;
	return (intGenerator);
}

int main()
{
	std::vector<int> intVector(10);
	srand((unsigned)time(0));
	std::generate(intVector.begin(), intVector.end(), createIntVector);

	for (int i = 0; i < 10; i++)
		std::cout << intVector[i] << " ";
		std::cout << std::endl;
	try
	{
		easyfind(intVector, 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

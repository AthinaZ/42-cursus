/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:43:53 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/25 17:43:54 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen karen;

	if (argc == 1)
	{
		std::cout << "ERROR: Please insert a level choosing from the following: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	karen.complain(argv[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:22 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 16:53:24 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	int			i;
	Phonebook	book;
	std::string	cmd = "";

	std::cout << "\n******* Welcome to my AWESOME PHONEBOOK *******\n" << std::endl;
	i = 1;
	while (true)
	{
		if (i == 9)
			i = 1;
		std::cout << "Type 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(0);
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
		{
			book.add(i);
			i++;
		}
		else if (cmd == "SEARCH")
			book.search();
		else
			std::cout << "Invalid syntax!!!" << std::endl;
	}
	return (0);
}



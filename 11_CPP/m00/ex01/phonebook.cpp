/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:49 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 16:53:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->count = 0;
}

Phonebook::~Phonebook(void)
{}

void Phonebook::add(int i)
{
	this->book[i - 1].get_info(i);
	if (this->count < 8)
		this->count++;
	std::cout << "Contact number " << i << " created.\n" << std::endl;
	if (std::cin.eof())
			exit(0);
}

void Phonebook::search()
{
	int	i = 0;

	if (!this->count)
	{
		std::cout << "PhoneBook is empty :(" << std::endl;
		return ;
	}
	(book)->print_header();
	while (i < this->count)
	{
		this->book[i].print_table();
		i++;
	}
	while (true)
	{
		std::cout << "Please input a digit between 1-8" << std::endl;
		std::string index;
		std::getline(std::cin, index);
		if (std::cin.eof())
			exit(0);
		i = atoi(index.c_str());
		if (i > this->count || i < 0)
			std::cout << "Contact does not exist\n" << std::endl;
		if (i <= this->count && i > 0)
			return this->book[i - 1].print_contact();
	}
}


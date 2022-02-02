/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:52:32 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/22 16:52:45 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

std::string fields[5] =
{
	"FIRST NAME",
	"LAST NAME",
	"NICKNAME",
	"PHONE NUMBER",
	"DARKEST SECRET"
};

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::get_info(int i)
{
	int	c = 0;

	std::cout << "Enter your contact information..." << std::endl;
	while (c < 5)
	{
		this->index = i;
		std::cout << fields[c] << ": ";
		std::getline(std::cin, this->field_info[c]);
		if (std::cin.eof())
			exit(0);
		c++;
	}
}

void	Contact::print_header()
{
	int	i = 0;

	std::cout << std::setw(10) << "INDEX" << "|";
	while(i < 3)
		std::cout << std::setw(10) << fields[i++] << "|";
	std::cout << std::endl;
}

void	Contact::print_table()
{
	int i = 0;

	std::cout << std::setw(10) << this->index << "|";
	while (i < 3)
	{
		std::cout << std::setw(10);
		if (field_info[i].size() <= 10)
			std::cout << field_info[i];
		else
			std::cout << field_info[i].substr(0, 9) + ".";
		std::cout << "|";
		i++;
	}
	std::cout << std::endl;
}

void	Contact::print_contact()
{
	int i = 0;

	std::cout << '\n';
	while (i < 5)
	{
		std::cout << fields[i] << ": ";
		std::cout << this->field_info[i] <<std::endl;
		i++;
	}
	std::cout << '\n';
}


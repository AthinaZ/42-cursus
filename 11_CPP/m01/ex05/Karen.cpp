/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:22:53 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/25 16:22:55 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{

}

Karen::~Karen()
{

}

void	Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void 	Karen::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void 	Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std:: cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	enum levels
	{	debug = 0,
		info,
		warning,
		error
	};
	void (Karen:: *complaints[4])() = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error};

	std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i <= 3 ; i++)
		if (array[i].compare(level) == 0)
			(this->*complaints[i])();
}

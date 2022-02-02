/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:31:31 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/23 15:31:32 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str;

	str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;

	std::string &stringREF = str;

	std::cout << '\n' << std::endl;
	std::cout << "Created the following string: " << str << '\n' << std::endl;

	std::cout << "The original string address is: " << &str << std::endl;
	std::cout << "Using stringPTR the address is: " << &(*stringPTR) << std::endl;
	std::cout << "Using stringREF the address is: " << &stringREF << std::endl;

	std::cout << '\n' << std::endl;

	std::cout << "Original string: " << str << std::endl;
	std::cout << "Using stringPTR: " << *stringPTR << std::endl;
	std::cout << "Using stringREF: " << stringREF << std::endl;

	std::cout << '\n' << std::endl;
	return (0);
}

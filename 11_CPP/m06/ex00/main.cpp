/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:56:49 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:40:59 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "ERROR: need an argument" << std::endl;
	else if (argc > 2)
		std::cout << "ERROR: too many arguments" << std::endl;
	else
	{
		Conversion convert(argv[1]);
	}
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:50:40 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:58:55 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int i[5] = {2, 54, 13, 26, 4};
	char c[6] = "hello";
	std::string bar[5] = {"hi", "how", "are", "you", "?"};

	std::cout << "------------------------------------" << std::endl;
	iter(i, 5, printElement);
	std::cout << "------------------------------------" << std::endl;
	iter(c, 5, printElement);
	std::cout << "------------------------------------" << std::endl;
	iter(bar, 5, printElement);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "BYE :)" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	
	return (0);
}

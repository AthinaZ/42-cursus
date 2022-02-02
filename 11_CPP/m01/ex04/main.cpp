/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:36:33 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/24 16:36:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Error: incorrect arguments" << std::endl;
		return 1;
	}
	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inputf(file);
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: cannot be empty" << std::endl;
		return (1);
	}
	if (!inputf)
	{
		std::cout << "Error: file does not exist" << std::endl;
		return 1;
	}
	else
	{
		std::ifstream inputf(file);
		if (inputf.is_open())
			std::cout << inputf.rdbuf();
		inputf.close();
	}
	std::ofstream outputf(file + ".replace");
	if (!outputf)
	{
		std::cout << "Error: could not open filename.replace for writing" << std::endl;
		return 1;
	}
	std::string strInput;
	while (getline(inputf, strInput))
	{
		int pos = 0;
		while ((pos = strInput.find(s1, pos)) != std::string::npos)
		{
			strInput.erase(pos, s1.length());
			strInput.insert(pos, s2);
			pos += s2.length();
		}
		outputf << strInput << std::endl;
		std::cout << strInput << std::endl;
	outputf.close();
	}
	return 0;
}



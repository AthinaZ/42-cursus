/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:39:11 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 16:07:19 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Catching exceptions for <Bur1> with <151> and <Bur2> with grade <0>" << std::endl;
	try
	{
		Bureaucrat bur1("Bur1", 151); //too low
		std::cout << bur1;
	}
	catch( std::exception& e)
	{
		std::cerr << "<Bur1> " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur2("Bur2", 0); //too high
		std::cout << bur2;
	}
	catch(const std::exception& e)
	{
		std::cerr << "<Bur2> " << e.what() << '\n';
	}
	try
	{
		Bureaucrat bur3("Bur3", 150); //ok
		std::cout << bur3;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureaucrat grade: " << e.what() << '\n';
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Incrementing and decrementing and catching exceptions!!" << std::endl;
	Bureaucrat bur4("Bur4", 130);
	std::cout << bur4;
	try
	{
		std::cout << "Decrementing Bur4...\n";
		bur4.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat bur5("Bur5", 150);
	std::cout << bur5;
	try
	{
		std::cout << "Decrementing Bur5...\n";
		bur5.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat bur6("Bur6", 1);
	std::cout << bur6;
	try
	{
		std::cout << "Incrementing Bur6...\n";
		bur6.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat bur7("Bur7", 3);
	std::cout << bur7;
	try
	{
		std::cout << "Incrementing...\n";
		bur7.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

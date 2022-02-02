/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:41:22 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 19:10:10 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat Tim("Timmy", 150);
	Bureaucrat Tom("Tommy", 50);
	Bureaucrat Rob("Robby", 76);
	Bureaucrat Bob("Bobby", 1);
	std::cout << Tim << Tom << Rob << Bob;

	Form a("Form A", 75, 60);
	std::cout << "Can Timmy sign Form A with grade to sign <75> ?" << std::endl;
	try
	{
		Tim.signForm(a);
		//std::cout << a;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Can Unmakeable form be created?" << std::endl;
	try
	{
		Form tooLow("UnmakeableForm", 200, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "No, because: " << e.what() << '\n';
	}
	std::cout << "Can Robby sign Form A?" << std::endl;
	try
	{
		//std::cout << a;
		Rob.signForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Incrementing Robby's grade..." << std::endl;
	Rob.incrementGrade();
	std::cout << "Can Robby now sign Form A??" << std::endl; 
	try
	{
		Rob.signForm(a);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

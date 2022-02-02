/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:46:50 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 22:42:45 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
	Intern someRandomIntern;
	Form *rrf;
	Form *ppf;
	Form *scf;
	Form *noForm;
	Bureaucrat Bob("Bobby", 44);
	Bureaucrat Rob("Robby", 140);
	Bureaucrat Tim("Timmy", 55);
	Bureaucrat Tom("Tommy", 4);
	Bureaucrat Sam("Sammy", 10);

	try
	{
		noForm = someRandomIntern.makeForm("Super form", "Wrong");
	}
	catch(const std::exception& e)
	{
		std::cerr << "<noForm> cannot be created because: " << e.what() << '\n';
	}

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bob.signForm(*rrf);
		Bob.executeForm(*rrf);
		//Tim.executeForm(*rrf);
		Tim.signForm(*rrf);
		Tim.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		scf = someRandomIntern.makeForm("shrubbery creation", "home");
		Tom.signForm(*scf);
		Tom.executeForm(*scf);
		Rob.signForm(*scf);
		Rob.executeForm(*scf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		ppf = someRandomIntern.makeForm("presidential pardon", "Sally");
		Tom.signForm(*ppf);
		Tom.executeForm(*ppf);
		Sam.signForm(*ppf);
		Sam.executeForm(*ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}




	delete rrf;
	delete scf;
	delete ppf;
	return 0;
}

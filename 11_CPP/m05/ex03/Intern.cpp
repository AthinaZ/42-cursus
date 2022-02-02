/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:46:24 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 22:42:46 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &intern)
{
	(void)intern;
}

Intern &Intern::operator=(Intern const &intern)
{
	(void)intern; // this is to avoid the unused parameter warning
	return (*this);
}

Intern::~Intern()
{

}

Form *shrForm(std::string const &formName, std::string const &target)
{
	(void)formName;
	return new ShrubberyCreationForm(target);
}

Form *robotForm(std::string const &formName, std::string const &target)
{
	(void)formName;
	return new RobotomyRequestForm(target);
}

Form *presidentForm(std::string const &formName, std::string const &target)
{
	(void)formName;
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string	type[3] = {"shrubbery creation","robotomy request", "presidential pardon"};
	Form	*(*newForm[3])(std::string const &formName, std::string const &target) = {&shrForm, &robotForm, &presidentForm};

	for (int i = 0; i < 3; i++)
	{
		if (type[i] == formName)
		{
			std::cout << "<Intern> creates " << formName << " targeted on <" << target << ">" <<std::endl;
			return (newForm[i])(formName, target);
		}
	}
	throw Intern::InternException();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:39:06 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 21:18:35 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Tim("Timmy", 145);
	Bureaucrat Tom("Tommy", 40);
	Bureaucrat Rob("Robby", 76);
	Bureaucrat Bob("Bobby", 1);
	Bureaucrat Sam("Sammy", 20);
	Bureaucrat Cat("Cathy", 138);
	std::cout << Tim << Tom << Rob << Bob;

	ShrubberyCreationForm a("PalmTree"); //145,137
	RobotomyRequestForm b("Robotomized"); //72,45
	PresidentialPardonForm c("Sally"); //25,5
	ShrubberyCreationForm d("Shrubby");

	Tim.signForm(a);
	std::cout << a;
	Tim.executeForm(a);
	while (Tim.getGrade() != a.getGradeToExecute())
		Tim.incrementGrade();
	//Tim.signForm(a);
	Tim.executeForm(a);
	Tom.signForm(b);
	std::cout << b;
	Tom.executeForm(b);
	Cat.signForm(d);
	Cat.executeForm(d);
	Bob.executeForm(c);
	std::cout << c;
	Sam.signForm(c);
	Bob.executeForm(c);
	//std::cout << c;

	return (0);
}



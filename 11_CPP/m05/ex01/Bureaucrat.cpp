/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:40:32 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 19:19:25 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
	*this = bur;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &bur)
{
	this->_grade = bur._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 == 151)
	{
		std::cout << "Cannot decrement: ";
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade++;
	std::cout << "New grade of bureaucrat <" << getName() << "> is <" << getGrade() << ">\n";

}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 == 0)
	{
		std::cout << "Cannot increment:";
		throw (Bureaucrat::GradeTooHighException());
	}
	this->_grade--;
	std::cout << "New grade of bureaucrat <" << getName() << "> is <" << getGrade() << ">\n";
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bur)
{
	out << "<" << bur.getName() << "> bureaucrat grade <" << bur.getGrade() << ">\n";
	return out;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:57 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 21:28:53 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _sign(false), _gradeToSign(150), _gradeToExecute(150)
{

}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	this->_sign = false;
}

Form::Form(const Form &form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	*this = form;
}

Form &Form::operator = (const Form &form)
{
	this->_sign = form._sign;
	return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSign() const
{
	return this->_sign;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeToSign)
	{
		std::cout << "<" << bur.getName() << "> cannot sign " << getName() << " because ";
		throw (Form::GradeTooLowException());
	}
	_sign = true;
	std::cout << "<" << bur.getName() << "> signs " << getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
	if (form.getSign())
		out << "Form Name: <" << form.getName() << "> -- Grade to sign <" << form.getGradeToSign() << "> -- Grade to execute <" << form.getGradeToExecute() << "> -- Signed: YES\n";
	else
		out << "Form Name: <" << form.getName() << "> -- Grade to sign <" << form.getGradeToSign() << "> -- Grade to execute <" << form.getGradeToExecute() << "> -- Signed: NO\n";
	return out;
}

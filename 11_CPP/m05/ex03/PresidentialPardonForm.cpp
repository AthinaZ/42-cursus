/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:06 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 22:42:51 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = "Default PP";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf)
{
	*this = ppf;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &ppf)
{
	_target = ppf._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw(Form::FormNotSignedException());
	if (executor.getGrade() <= this->getGradeToExecute())
		std::cout << "<" << this->_target << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	else
	{
		throw(Bureaucrat::GradeTooLowException());
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:24 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 22:42:49 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	this->_target = "Default RR";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
{
	*this = rrf;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &rrf)
{
	_target = rrf._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw(Form::FormNotSignedException());
	if(executor.getGrade() <= this->getGradeToExecute())
		std::cout << "drillzzzzzzzz <" << executor.getName() << "> has been robotomized successfully 50% of the time" << std::endl;
	else
		throw(Bureaucrat::GradeTooLowException());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:44:30 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 22:27:43 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = "Default SC";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
{
	*this = scf;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &scf)
{
	_target = scf._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw(Form::FormNotSignedException());
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		std::ofstream outFile(_target + "_shrubbery");
		if (!outFile.is_open())
		{
			std::cout << "File could not be opened :(" << std::endl;
			return;
		}
		outFile << "###########################'`################################" << std::endl
				<< "###########################  V##'############################" << std::endl
				<< "#########################V'  `V  ############################" << std::endl
				<< "########################V'      ,############################" << std::endl
				<< "#########`#############V      ,A###########################V " << std::endl
				<< "########' `###########V      ,###########################V',#" << std::endl
				<< "######V'   ###########l      ,####################V~~~~'',###" << std::endl
				<< "#####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl
				<< "#####l      d#########l      V'  ,#######V~'       A#########" << std::endl
				<< "#####l      ##########l         ,####V''         ,###########" << std::endl
				<< "#####l        `V######l        ,###V'   .....;A##############" << std::endl
				<< "#####A,         `######A,     ,##V' ,A#######################" << std::endl
				<< "#######A,        `######A,    #V'  A########'''''##########''" << std::endl
				<< "##########,,,       `####A,           `#''           '''  ,,," << std::endl
				<< "#############A,                               ,,,     ,######" << std::endl
				<< "######################oooo,                 ;####, ,#########" << std::endl
				<< "##################P'                   A,   ;#####V##########" << std::endl
				<< "#####P'    ''''       ,###             `#,     `V############" << std::endl
				<< "##P'                ,d###;              ##,       `V#########" << std::endl
				<< "##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl
				<< "#############A, Y#########A,            )####, ,#############" << std::endl
				<< "###############A ############A,        ,###### ##############" << std::endl
				<< "###############################       ,#######V##############" << std::endl
				<< "###############################      ,#######################" << std::endl
				<< "##############################P    ,d########################" << std::endl
				<< "##############################'    d#########################" << std::endl
				<< "##############################     ##########################" << std::endl
				<< "##############################     ##########################" << std::endl
				<< "#############################P     ##########################" << std::endl
				<< "#############################'     ##########################" << std::endl
				<< "############################P      ##########################" << std::endl
				<< "###########################P'     ;##########################" << std::endl
				<< "###########################'     ,###########################" << std::endl
				<< "##########################       ############################" << std::endl
				<< "#########################       ,############################" << std::endl
				<< "########################        d###########P'    `Y#########" << std::endl
				<< "#######################        ,############        #########" << std::endl
				<< "######################        ,#############        #########" << std::endl
				<< "#####################        ,##############b.    ,d#########" << std::endl
				<< "####################        ,################################" << std::endl
				<< "###################         #################################" << std::endl;
		outFile.close();
	}
	else
	{
		throw(Bureaucrat::GradeTooLowException());
	}
}


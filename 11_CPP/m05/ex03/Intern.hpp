/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:46:41 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 21:37:04 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &intern);
		Intern &operator=(Intern const &intern);
		~Intern();

		Form *makeForm(std::string  const &formName, std::string const &target);
		class InternException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("REQUEST FORM NOT KNOWN");
				}
		};

};


#endif

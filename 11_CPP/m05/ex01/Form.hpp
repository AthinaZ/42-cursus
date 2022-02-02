/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:40:41 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 19:08:28 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _sign;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &form);
		Form &operator = (const Form &form);
		~Form();
		class	GradeTooHighException : public std::exception
		{
			public:
				const char * what () const throw ()
				{
					return "GRADE TOO HIGH";
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char * what () const throw ()
				{
					return "GRADE TOO LOW";
				}
		};
		std::string getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bur);
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif

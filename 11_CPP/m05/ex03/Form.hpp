/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:46:10 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 21:21:14 by azouzoul         ###   ########.fr       */
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
		virtual ~Form();
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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char * what () const throw ()
				{
					return "FORM HAS NOT BEEN SIGNED";
				}
		};
		std::string getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bur);
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, Form &form);

#endif
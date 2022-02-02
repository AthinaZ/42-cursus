/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:45:47 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/19 15:45:54 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bur);
		Bureaucrat &operator= (const Bureaucrat &bur);
		~Bureaucrat();
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
		int getGrade() const;
		void decrementGrade();
		void incrementGrade();
		void signForm(Form &form);
		void executeForm(Form const &form);
};
	std::ostream &operator<<(std::ostream &out, Bureaucrat &bur);

#endif

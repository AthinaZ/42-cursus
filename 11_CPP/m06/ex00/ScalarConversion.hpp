/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:55:56 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 12:56:01 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
# define SCALAR_CONVERSION_HPP

#include <iostream>
#include <iomanip> //setprecision
#include <string> //stod,c_str
#include <cfloat> // flt-max, dbl-max
#include <climits> //int-max 
#include <cstdlib> //atof, atoi
#include <cctype> //isprint, isdigit

class Conversion
{
	private:
		std::string _arg;

	public:
		Conversion();
		Conversion(std::string arg);
		Conversion(const Conversion &copy);
		Conversion& operator=(const Conversion &op);
		~Conversion();

		std::string	getArg() const;
		void	fromChar(std::string arg);
		void	invalidInput();
		void	fromDouble();
		void 	myNan(std::string arg);
		void 	myInfinity(std::string arg);
		double	Double;
		bool	zero;
};

#endif

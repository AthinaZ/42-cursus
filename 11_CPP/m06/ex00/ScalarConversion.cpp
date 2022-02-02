/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:56:05 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:42:58 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

Conversion::Conversion(): _arg("default"), Double(0), zero(false)
{

}

Conversion::Conversion(std::string arg) : _arg(arg), Double(0), zero(false)
{
	try
	{
		if (arg == "nan" || arg == "nanf")
			myNan(arg);
		else if (arg == "-inff" || arg == "+inff" || arg == "-inf"|| arg == "+inf" || arg == "inf" || arg == "inff")
			myInfinity(arg);
		else
		{
			if (atof(arg.c_str()) - atoi(arg.c_str()) == 0.0)
				zero = true;
			Double = std::stod(arg);
			fromDouble();
		}
	}
	catch(const std::exception &e)
	{
		if (arg.length() == 1)
			fromChar(arg);
		else
			invalidInput();
	}
}

Conversion::Conversion(const Conversion &copy) : _arg(copy._arg)
{
	*this = copy;
}

Conversion &Conversion::operator=(const Conversion &op)
{
	this->_arg = op._arg;
	return *this;
}

Conversion::~Conversion()
{
	
}

void	Conversion::fromChar(std::string arg)
{
	/* ----- TO CHAR ----- */
	if (isprint(arg.c_str()[0]))
		std::cout << "char: '" << static_cast<char>(arg.c_str()[0]) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	/* ----- TO INT ------ */
	std::cout << "int: " << static_cast<int>(arg.c_str()[0]) << std::endl;
	/* ----- TO FLOAT ----- */
	std::cout << "float: " << static_cast<float>(arg.c_str()[0]) << ".0f" << std::endl;
	/* ----- TO DOUBLE ----- */
	std::cout << "double: " << static_cast<double>(arg.c_str()[0]) << ".0" << std::endl;
	return ;
}

void	Conversion::fromDouble()
{
	std::cout << std::setprecision(7);
	// std::cout << std::fixed;
	// std::cout << std::showpoint;
	
	/* ----- TO CHAR ----- */
	if (isprint(Double))
		std::cout << "char: '" << static_cast<char>(Double) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	/*  ----- TO INT ----- */
	if (Double > INT_MIN && Double < INT_MAX)
		std::cout << "int: " << static_cast<int>(Double) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	/* ----- TO FLOAT ----- */
	if (zero && (Double >= -FLT_MAX || Double <= FLT_MAX))
		std::cout << "float: " << static_cast<float>(Double) << ".0f" << std::endl;
	else if (Double > -FLT_MAX || Double < FLT_MAX)
		std::cout << "float: " << static_cast<float>(Double) << "f" << std::endl;
	/* ----- TO DOUBLE ----- */
	if (zero && (Double > -DBL_MAX || Double < DBL_MAX))
		std::cout << "double: " << Double << ".0" << std::endl;
	else if (Double > -DBL_MAX || Double < DBL_MAX)
		std::cout << "double: " << Double << std::endl;
	
	
}

void	Conversion::myNan(std::string arg)
{
	if (arg == "nan" || arg == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossibile" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void Conversion::myInfinity(std::string arg)
{
	if (arg == "+inf" || arg == "+inff" || arg == "inf" || arg == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossibile" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (arg == "-inf" || arg == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossibile" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	Conversion::invalidInput()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossibile" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

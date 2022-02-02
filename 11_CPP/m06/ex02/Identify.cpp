/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:17:04 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:53:25 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch (rand() % 4)
	{
		case 0 :
			std::cout << "Type A created." << std::endl;
			return (new A);
			break;
		case 1 :
			std::cout << "Type B created." << std::endl;
			return (new B);
			break;
		case 2 :
			std::cout << "Type C created." << std::endl;
			return (new C);
			break;
		default:
			std::cout << "Type BASE created." << std::endl;
			return (new Base);
			break;		
	}
	return (0);
}

void	pidentify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a != 0)
	{
		std::cout << "Pointer : A" << std::endl;
		return ;
	}

	else if (b != 0)
	{
		std::cout << "Pointer : B" << std::endl;
		return ;
	}

	else if (c != 0)
	{
		std::cout << "Pointer : C" << std::endl;
		return ;
	}
	else
		std::cout << "Pointer : Not a Base derived class" << std::endl;
}

void	ridentify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p); // void to remove unused variable warning
		(void)a;
		std::cout << "Reference : A" << std::endl;
		return ;
	}
	catch(const std::bad_cast&)
	{}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Reference : B" << std::endl;
		return ;
	}
	catch(const std::bad_cast&)
	{}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Reference : C" << std::endl;
		return ;
	}
	catch(const std::bad_cast&)
	{}
	std::cout << "Reference : Not a Base derived class" << std::endl;
}

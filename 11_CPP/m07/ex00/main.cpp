/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:49:40 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:49:42 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	{
		std::cout << "Main from subject" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << "------------------------------" << std::endl;
	std::cout << "SWAP" << std::endl;
	std::cout << "------------------------------" << std::endl;
	int a = 2;
	int b = 3;
	char c = 'h';
	char d = 'k';
	std::string e = "chaine1";
	std::string f = "chaine2";

	std::cout << "int a before swap is " << a << std::endl;
	std::cout << "int b before swap is " << b << std::endl;
	::swap( a, b );
	std::cout << "int a after swap is " << a << std::endl;
	std::cout << "int b after swap is " << b << std::endl;

	std::cout << "char c before swap is " << c << std::endl;
	std::cout << "char d before swap is " << d << std::endl;
	::swap(c, d);
	std::cout << "char c after swap is " << c << std::endl;
	std::cout << "char d after swap is " << d << std::endl;

	std::cout << "str e before swap is " << e << std::endl;
	std::cout << "str f before swap is " << f << std::endl;
	::swap(e, f);
	std::cout << "str e after swap is " << e << std::endl;
	std::cout << "str f after swap is " << f << std::endl;


	int i = 2;
	int j = 5;
	double k = 4.6;
	double l = 7.2;
	char m = 'm';
	char n = 'n';
	int p = 5;
	int q = 5;
	
	std::cout << "------------------------------" << std::endl;
	std::cout << "MIN" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "min(2,5) = " << ::min<int>(i, j) << std::endl;
	std::cout << "min(m,n) = " << ::min<char>(m, n) << std::endl;
	std::cout << "min(4.6,7.2) = " << ::min<double>(k, l) << std::endl;
	std::cout << "min(chaine1,chaine2) = " << ::min(e, f) << std::endl;

	std::cout << "------------------------------" << std::endl;
	std::cout << "MAX" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "max(2,5) = " << ::max<int>(i, j) << std::endl;
	std::cout << "max(5,5) = " << ::min<double>(p, q) << std::endl;
	std::cout << "max(chaine1, chaine2) = " << ::max(e, f) << std::endl;


	std::cout << "------------------------------" << std::endl;
	std::cout << "END :)" << std::endl;
	std::cout << "------------------------------" << std::endl;
	
	return (0);
}

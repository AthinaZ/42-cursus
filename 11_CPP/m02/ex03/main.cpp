/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:27:41 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:27:43 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	{
		//IN
		Point a(0,1);
		Point b(0,5);
		Point c(3,3);
		Point point(1,3);
		std:: cout << bsp(a,b,c,point) << " = TRUE" << " -> POINT IS INSIDE TRIANGLE because sum of three areas equal area" <<std::endl;
	}
	{
		//IN
		Point a(0.7,0.6);
		Point b(7,7.5);
		Point c(13.4,1.7);
		Point point(8,3);
		std:: cout << bsp(a,b,c,point) << " = TRUE" << " -> POINT IS INSIDE TRIANGLE because sum of three areas equal area" << std::endl;
	}
	{
		//Side
		Point a(1,1);
		Point b(3,1);
		Point c(4,2);
		Point point(2,1);
		std:: cout << bsp(a,b,c,point) << " = FALSE" << " -> POINT IS ON A SIDE because one of the areas equals zero (sums irrelevant in this case)!"<< std::endl;
	}
	{
		//OUT
		Point a(1,1);
		Point b(3,1);
		Point c(4,2);
		Point point(1,3);
		std:: cout << bsp(a,b,c,point) << " = FALSE" << " -> POINT IS OUTSIDE TRIANGLE because sum of three areas is greater than area" << std::endl;
	}
	{
		//OUT
		Point a(1,1);
		Point b(3,1);
		Point c(4,2);
		Point point(100,300);
		std:: cout << bsp(a,b,c,point) << " = FALSE" << " -> POINT IS OUTSIDE TRIANGLE because sum of three areas is greater than area" << std::endl;
	}
	return 0;
}


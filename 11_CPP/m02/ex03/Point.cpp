/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:29:00 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:29:02 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{

}

Point::Point(const float X, const float Y) : x(X), y(Y)
{

}

Point::Point(const Point &copy): x(copy.x), y(copy.y)
{
	*this = copy;
}

Point::~Point()
{

}

Point &Point::operator=(const Point &pt)
{
	return *this;
}

Fixed Point::area(const Point a, const Point b, const Point c)
{

	Fixed determinant;
	determinant = ((c.x - a.x) * (b.y - a.y)) - ((b.x - a.x) * (c.y - a.y));
	if (determinant < 0)
		determinant = determinant * Fixed(-1); //absolute values of all ints and floats in Fixed class
	return Fixed((float)(0.5)) * determinant;
}


// https://www.tutorialspoint.com/cplusplus-program-to-compute-the-area-of-a-triangle-using-determinants

// In this section we will see how to find the area of a triangle in 2D coordinate space using matrix determinants. In this case we are considering the space is 2D. So we are putting each points in the matrix. Putting x values at the first column, y into the second and taking 1 as the third column. Then find the determinant of them. The area of the triangle will be half of the determinant value. If the determinant is negative, then simply take the absolute value of it.
// determinant = |x1 y1 1| a
// 				 |x2 y2 1| b
// 				 |x3 y3 1| c

// Area = absolute value of 0.5 * determinant
//
// Area = 0.5 | x3 - x1  y3 - y1 |
//		      | x2 - x1  y2 - y1 |
//
// Area = 0.5[(x3 - x1)(y2 - y1) - (x2 - x1)(y3 - y1)]

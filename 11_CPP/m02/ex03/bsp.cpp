/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:29:30 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/30 20:29:31 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = Point::area(a, b, c);
	Fixed area1 = Point::area(a, b, point);
	Fixed area2 = Point::area(a, point, c);
	Fixed area3 = Point::area(point, b, c);

	std::cout << "Area:  " << area << std::endl;
	std::cout << "Area1: " << area1 << std::endl;
	std::cout << "Area2: " << area2 << std::endl;
	std::cout << "Area3: " << area3 << std::endl;
	std::cout << "SUM:   " << area1 + area2 + area3 << std::endl;

	if (area1 == 0 || area2 == 0 || area3 == 0 || (area1 + area2 + area3) > area)
		return false; // 0 - outside triangle or on a side
	return true; // 1 - inside triangle
}

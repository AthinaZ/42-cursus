/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:49:27 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:58:13 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &x, T &y)
{
	T temp = y;
	y = x;
	x = temp;
}

template <typename T>
T const min(T const &x, T const &y)
{
	if (x == y)
		return(y);
	else if(x > y)
		return (y);
	return(x);
}

template <typename T>
T const max(T const &x, T const &y)
{
	if (x == y)
		return(y);
	else if(x > y)
		return (x);
	return(y);
}

#endif

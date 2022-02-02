/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:50:56 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:58:46 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void f(T &arrElement))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void printElement(T &element)
{
	std::cout << element << " " << std::endl;
}

#endif
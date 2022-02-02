/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:41 by azouzoul          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:48 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class	NotFoundException : public std::exception
{
	public:
		const char * what() const throw()
		{
			return ("Element - 12 - NOT FOUND");
		}
};

template <typename T>
int easyfind(T t, int i)
{
	typename T::iterator it;

	it = find(t.begin(), t.end(), i);
	if (it != t.end())
		std::cout << "Element - " << i << " - FOUND." << std::endl;
	else
		throw NotFoundException();
	return (0);
}

#endif

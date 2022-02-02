/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:57:43 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:47:57 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t intp = reinterpret_cast<uintptr_t>(ptr);
	return(intp);
}

Data *deserialize(uintptr_t raw)
{
	Data* r = reinterpret_cast<Data*>(raw);
	return(r);
}

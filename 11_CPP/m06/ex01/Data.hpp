/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:57:24 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:09:04 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	int			_num;
	std::string	_str;
}				Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif

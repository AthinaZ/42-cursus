/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:58:08 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/26 13:06:38 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// The intptr_t and uintptr_t types are extremely useful for casting pointers when 
// you want to do address arithmetic. They should be used instead of long or unsigned long
// for this purpose. Use of uintptr_t for casting is usually safer than intptr_t ,
// especially for comparisons. Capable of storing a data pointer.


int main()
{
	Data	*data1 = new Data();
	Data	*data2;

	data1->_num = 24;
	data1->_str = "twentyfour";

	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "Data1 ADDRESS: " << data1 << std::endl;
	std::cout << "Data1 NUM: " << (*data1)._num << std::endl;
	std::cout << "Data1 STR: " << data1->_str << std::endl;

	uintptr_t raw = serialize(data1);
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "Data SERIALIZATION to raw: " << raw << std::endl;
	data2 = deserialize(raw);

	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "Raw DESERIALIZATION......." << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "Data2 ADDRESS: " << data2 << std::endl;
	std::cout << "Data2 NUM: " << data2->_num << std::endl;
	std::cout << "Data2 STR: " << data2->_str << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;

	delete (data1);

	return (0);
}


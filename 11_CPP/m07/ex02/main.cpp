/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:51:57 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:54:08 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "-------------------- TEST EMPTY ARRAY -------------------" << std::endl;
	Array<int>  empty;
	std::cout << "Empty array address: " << &empty << std::endl;
	std::cout << "Empty array length: " << empty.size() << std::endl;
	try
	{
		empty[1];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Element 1 of empty array does not exist - " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-------------------- TEST INT ARRAY ---------------------" << std::endl;
	Array<int> intArr(5);
	intArr[0] = 10;
	intArr[1] = 20;
	intArr[2] = 30;
	intArr[3] = 40;
	intArr[4] = 50;
	std::cout << "Contents of int array: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------- TEST FLOAT ARRAY --------------------" << std::endl;
	Array<float> floatArr(5);
	floatArr[0] = 10.45f;
	floatArr[1] = 20.787f;
	floatArr[2] = 30.346f;
	floatArr[3] = 40.787f;
	floatArr[4] = 50.634f;
	std::cout << "Contents of float array: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << floatArr[i] << " ";
	std::cout << std::endl;

	std::cout << "-------------------- TEST CHAR ARRAY --------------------" << std::endl;
	Array<char> charArr(5);
	charArr[0] = '^';
	charArr[1] = '9';
	charArr[2] = 'd';
	charArr[3] = 'j';
	charArr[4] = 'E';
	std::cout << "Contents of char array: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << charArr[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------- TEST STRING ARRAY -------------------" << std::endl;
	Array<std::string> strArr(4);
	strArr[0] = "I love C++ templates...";
	strArr[1] = "How about you?";
	strArr[2] = "Finally almost done these modules";
	strArr[3] = "Oh geezzz, ft_containers is coming up next!";
	std::cout << "Contents of str array: " << std::endl;
	 for (unsigned int i = 0; i < 4; i++)
		std::cout << strArr[i] << std::endl;

	std::cout << "----------------- TEST COPY CONSTRUCTOR -----------------" << std::endl;
	Array<char> original(5);
	original[0] = 'a';
	original[1] = 'a';
	original[2] = 'a';
	original[3] = 'a';
	original[4] = 'a';
	Array<char> copy(original);
	std::cout << "Original array contents: " << std::endl;
	for (unsigned int i = 0; i < original.size(); i++)
		std::cout << original[i] << " ";
		std::cout << std::endl;
	std::cout << "Copied array contents: " << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
		std::cout << std::endl;

	std::cout << "-------------------- TEST DEEP COPY ---------------------" << std::endl;
	std::cout << "Show DEEP COPY:" << std::endl;
	std::cout << "Char array: " << std::endl;
	for (unsigned int i = 0; i < original.size(); i++)
		std::cout << original[i] << " ";
		std::cout << std::endl;
	std::cout << "Copied char array: " << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
		std::cout << std::endl;
	std::cout << "Change original char array: " << std::endl;
	original[0] = 'b';
	original[1] = 'b';
	original[2] = 'b';
	original[3] = 'b';
	original[4] = 'b';
	for (unsigned int i = 0; i < original.size(); i++)
		std::cout << original[i] << " ";
		std::cout << std::endl;
	std::cout << "Copied array remained unchanged:" << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
		std::cout << std::endl;

	std::cout << "-------------------- TEST ASSIGNMENT --------------------" << std::endl;
	Array<char> assignedArr = charArr;
	std::cout << "Original charArr:" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << charArr[i] << " ";
	std::cout << std::endl;
	std::cout << "Assigned charArr:" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << assignedArr[i] << " ";
	std::cout << std::endl;
	std::cout << "Changed elements of assigned charArray to:" << std::endl;
	assignedArr[0] = 'c';
	assignedArr[1] = 'c';
	assignedArr[2] = 'c';
	assignedArr[3] = 'c';
	assignedArr[4] = 'c';
	for (unsigned int i = 0; i < 5; i++)
		std::cout << assignedArr[i] << " ";
	std::cout << std::endl;
	std::cout << "Original charArr remains unchanged:" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << charArr[i] << " ";
	std::cout << std::endl;


	std::cout << "--------------- TEST ARRAY INDEX OPERATOR ---------------" << std::endl;
	std::cout << "Contents of int array: " << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;
	std::cout << "Access 4th element of int array:" << std::endl;
	try
	{
		std::cout << "4th element: " << intArr.operator[](3) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Access non existent element of int array:" << std::endl;
	try
	{
		std::cout << intArr.operator[](6);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot access: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "All done! Thanks for stopping by :)" << std::endl;
	std::cout << std::endl;
	
	return (0);
}

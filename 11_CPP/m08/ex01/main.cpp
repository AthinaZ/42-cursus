/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:16:14 by azouzoul          #+#    #+#             */
/*   Updated: 2022/02/01 17:21:55 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
		std::cout << std::endl;
		std::cout << "---------------- TEST FROM SUBJECT ----------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		//std::cout << "Size: " << sp.getSize() << std::endl;

		std::cout << "-------------------- OTHER TESTS ------------------" << std::endl;

		Span span(20000);
		int random;
		srand(std::time(0));
		// std::cout << "Maximum storage size of Span: " << span.getSize() << std::endl;
		// std::cout << "Number of Elements stored: " << span.getNumsStored() << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------- NO SPAN ---------------------" << std::endl;
		try
		{
			std::cout << span.shortestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << "Find shortest span -- Not possible: " << e.what() << std::endl;
		}
		try
		{
			std::cout << span.longestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << "Find longest span -- Not possible: " << e.what() << std::endl;
		}

		std::cout << "---------------- SIMPLE ADD NUMBER ----------------" << std::endl;
		std::cout << "Add 5 random numbers ->" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			random = (rand() % 100 - 42);
			span.addNumber(random);
			std::cout << "Added: " << random << std::endl;
		}
		// std::cout << "Created an array with size: " << span.getSize() << std::endl;
		std::cout << " -> Shortest span found is: " << span.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << span.longestSpan() << std::endl;
		// std::cout << "Number of Elements stored: " << span.getNumsStored() << std::endl;
		// std::cout << "Elements: " << span << std::endl;
		// std::cout << "Max storage size of Span: " << span.getSize() << std::endl;
		// std::cout << "Space remaining in Span: " << span.getRemaining() << std::endl;

		std::cout << "------------ USING ITERATOR ADD NUMBER ------------" << std::endl;
		std::vector<int> vector;
		vector.push_back(2000);
		std::cout << "Added: " << 2000 << " to vector" << std::endl;
		vector.push_back(250);
		std::cout << "Added: " << 250 << " to vector" << std::endl;
		vector.push_back(-2200);
		std::cout << "Added: " << -2200 << " to vector" << std::endl;
		vector.push_back(239);
		std::cout << "Added: " << 239 << " to vector" << std::endl;
		span.addNumber(vector.begin(), vector.end());
		std::cout << " -> Shortest span found is: " << span.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << span.longestSpan() << std::endl;
		// std::cout << "Size of vector array: " << vector.size() << std::endl;
		// std::cout << "Capacity of vector array: " << vector.capacity() << std::endl;
		// std::cout << "Number of Elements stored in vector: " << span.getNumsStored() << std::endl;
		// std::cout << "Space remaining in Span: " << span.getRemaining() << std::endl;
		// std::cout << "Size of vector: " << vector.size() << std::endl;
		// std::cout << "Updated Vector Elements: " << span << std::endl;

		std::cout << "----- USING ITERATOR and TESTING MAX CAPACITY -----" << std::endl;
		std::vector<int> vector2(15000);
		generate(vector2.begin(), vector2.end(), rand);
		span.addNumber(vector2.begin(), vector2.end());
		std::cout << " -> Shortest span found is: " << span.shortestSpan() << std::endl;
		std::cout << " -> Longest span found is: " << span.longestSpan() << std::endl;
		// std::cout << "Capacity of vector2 array: " << vector2.capacity() << std::endl;
		// std::cout << "Number of Elements stored: " << span.getNumsStored() << std::endl;
		// std::cout << "Space remaining in Span: " << span.getRemaining() << std::endl;
		//std::cout << "Size vector: " << span.getSize() << std::endl;

		// std::cout << "Can we fit any more numbers in vector2?" << std::endl;
		// std::cout << "Size of vector2 array: " << vector2.size() << std::endl;
		try
		{
			generate(vector2.begin(), vector2.end(), rand);
			span.addNumber(vector2.begin(), vector2.end());
			std::cout << " -> Shortest span found is: " << span.shortestSpan() << std::endl;
			std::cout << " -> Longest span found is: " << span.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			// std::cout << "Exception caught -> Capacity of vector2: " << vector2.capacity() << " therefore -- " << e.what() << std::endl;
			std::cout << "Exception caught -> " << e.what() << std::endl;
		}
		std::cout << std::endl;
		return (0);
}

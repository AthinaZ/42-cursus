/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <azouzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:55:08 by azouzoul          #+#    #+#             */
/*   Updated: 2022/01/28 16:55:11 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int num)
		{
			_array =  new T[num];
			_size = num;
		}

		Array(const Array &copy)
		{
			this->_array = new T[copy.size()];
			this->_size = copy.size();
			for (unsigned int i = 0; i < _size; i++)
				this->_array[i] = copy._array[i];
		}

		const Array& operator=(const Array &op)
		{
			this->_size = op._size();
			this->_array = new T[op.size()];
			for (unsigned int i = 0; i < _size; i++)
				this->_array[i] = op._array[i];
			return(*this);
		}

		~Array()
		{
			delete [] (_array);
		}

		unsigned int size(void) const
		{
			return (_size);
		}

		T & operator[](unsigned int idx)
		{
			if (idx > _size || idx < 0)
			{
				throw OutOfRangeException();
			}
			else
				return _array[idx];

		};

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Out of Range");
				}
		};

};

#endif

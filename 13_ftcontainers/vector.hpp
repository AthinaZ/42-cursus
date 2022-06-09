#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <new>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/*********** TYPEDEFS, ALLOCATOR, MEMBER TYPES ***********/
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::iterator_vector<T *>						iterator;
			typedef ft::iterator_vector<const T *>					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:
			pointer		_array;
			size_t		_size;
			size_t		_capacity;
			Allocator	_allocator;

		public:
			/*********** CONSTRUCTORS, DESTRUCTORS, COPY, ASSIGNMENT OPERATOR ***********/
			explicit vector(const allocator_type &alloc = allocator_type())
			: _array(0), _size(0), _capacity(0), _allocator(alloc) {} // default

			explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
			: _array(0), _size(0), _capacity(0), _allocator(alloc) // fill
			{
				assign(n, val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) //range
			: _array(0), _size(0), _capacity(0), _allocator(alloc)
			{
				assign(first, last);
			}

			vector (const vector &x)
			: _array(0), _size(0), _capacity(0), _allocator(x._allocator)
			{
				assign(x.begin(), x.end());
			}

			~vector()
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(_array + i);
				if (_capacity)
					_allocator.deallocate(_array, _capacity);
			}

			vector &operator = (const vector &obj)
			{
				assign(obj.begin(), obj.end());
				return *this;
			}

			/****** ITERATOR ******/

			iterator begin() {return iterator(_array);}
			iterator end() {return iterator(_array + _size);}
			const_iterator begin() const {return const_iterator(_array);}
			const_iterator end() const {return const_iterator(_array + _size);}
			reverse_iterator rbegin() {return reverse_iterator(end());}
			reverse_iterator rend() {return reverse_iterator(begin());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
			const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

			/****** CAPACITY ******/

			size_type size() const {return (_size);}
			size_type max_size() const {return (_allocator.max_size());}
			size_t capacity() const {return (_capacity);}
			bool empty() const {return (size()== 0);}

			void reserve(size_type n)
			{
				if (!n)
					_capacity = 1;
				if (n > _capacity)
					_capacity = n;
				pointer tmp = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i) {
					_allocator.construct(tmp + i, _array[i]);
					_allocator.destroy(&_array[i]);
				}
				_allocator.deallocate(_array, _size);
				_array = tmp;
			}

			void resize( size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					pointer tmp = _allocator.allocate(n);
					for (size_type i = 0; i < n; i++)
						tmp[i] = _array[i];
					_allocator.deallocate(_array, _size);
					_array = tmp;
					_size = n;
				}
				else if (n >= _size) {
					if (n < _capacity || n > capacity() * 2)
						reserve(n);
					else
						reserve(capacity() * 2);
					for (size_type i = _size; i < n; i++)
						_allocator.construct(_array + i, val);
					_size = n;
				}
			}

			/****** ELEMENT ACCESS ******/

			reference operator[](size_type n) {return (*(_array + n));}
			const reference operator[](size_type n) const {return (*(_array + n));}
			reference at (size_type n)
			{
				if (n > _size)
					throw(std::out_of_range(" : Out of Range error: vector"));
				return _array[n];
			}

			const_reference at (size_type n) const
			{
				if (n > _size)
					throw(std::out_of_range(" : Out of Range error: vector"));
				return _array[n];
			}

			reference front()
			{
				return _array[0];
			}

			const_reference front() const
			{
				return _array[0];
			}

			reference back()
			{
				return _array[_size - 1];
			}

			const_reference back() const
			{
				return _array[_size - 1];
			}

			/****** MODIFIERS ******/

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				clear();

				for(InputIterator tmp = first; tmp != last; tmp++)
					_size++;

				if (_size > _capacity)
				{
					if (_capacity)
						_allocator.deallocate(_array, _capacity);
					_capacity = _size;
					_array = _allocator.allocate(_capacity);
				}

				size_type i = 0;
				while (first != last)
				{
					_allocator.construct(_array + i, *first);
					first++;
					i++;
				}
			}

			void assign(size_type n, const value_type &val)
			{
				clear();
				_size = n;
				if (_size > _capacity)
				{
					if (_capacity)
						_allocator.deallocate(_array, _capacity);
					_capacity = _size;
					_array = _allocator.allocate(_capacity);
				}

				size_type i = 0;
				while (i < _size)
				{
					_allocator.construct(_array + i, val);
					i++;
				}
			}

			void push_back(const value_type &val)
			{
				reserve(_size + 1);
				_allocator.construct(_array + _size, val);
				_size++;
			}

			void pop_back()
			{
				if (_size)
				{
					_size--;
					_allocator.destroy(_array + _size);
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				if (position > end() || position < begin())
					throw std::logic_error("VECTOR -- INSERT FAILED");
				size_t pos = 0;
				for (iterator it = begin(); it != position; it++)
					pos++;
				if (_size >= _capacity)
					reserve(_capacity * 2);
				_size++;
				size_t iter = _size;
				while (iter != pos && (iter - 1) != pos)
				{
					_array[iter - 1] = _array[iter - 2];
					iter--;
				}
				_array[pos] = val;
				size_t index = 0;
				iterator i = begin();
				for (; index != pos; i++)
					index++;
				return (i);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (position > end() || position < begin())
					throw std::logic_error("VECTOR -- INSERT FAILED");
				size_t pos = 0;
				for (iterator it = begin(); it != position; ++it)
					pos++;
				if (_size + n > _capacity)
				{
					if (n >= size())
						reserve(_size + n);
					else
						reserve(size() * 2);
				}
				_size += n;
				size_t idx = _size;
				while (idx > pos && (idx - n) > pos)
				{
					_array[idx - 1] = _array[idx - n - 1];
					idx--;
				}
				size_t j = 0;
				while (j < n)
				{
					_array[pos] = val;
					pos++;
					j++;
				}
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				if (position > end() || position < begin())
					throw std::logic_error("VECTOR -- INSERT FAILED");
				size_t range = 0;
				for (InputIterator i = first; i != last; ++i)
					range++;
				size_t pos = 0;
				for (iterator it = begin(); it != position; ++it)
					pos++;
				if (_size + range > _capacity)
				{
					if (_size + range < _capacity || _size + range > capacity() * 2)
						reserve(_size + range);
					else
						reserve(capacity() * 2);
				}
				_size += range;
				size_t idx = _size;
				while (idx > pos && (idx - range) > pos)
				{
					_array[idx - 1] = _array[idx - range - 1];
					idx--;
				}
				for(; first != last; first++, pos++)
					_array[pos] = *first;

			}

			iterator erase(iterator position)
			{
				_size--;
				iterator i = (iterator)_array;
				size_t pos = 0;
				while (i < position)
				{
					pos++;
					i++;
				}
				while (pos != _size)
				{
					_array[pos] = _array[pos + 1];
					pos++;
				}
				return (position);
			}

			iterator erase (iterator first, iterator last)
			{
				size_t range = 0;
				iterator tmp;
				iterator tmp2 = (iterator)_array;
				size_t pos = 0;
				tmp = first;
				while (tmp2 != first)
				{
					tmp2++;
					pos++;
				}
				while (tmp != last)
				{
					tmp++;
					range++;
				}
				_size -= range;
				while (pos < _size)
				{
					_array[pos] = _array[pos + range];
					pos++;
				}
				return (first);
			}

			void swap (vector& x)
			{
				std::swap(_array, x._array);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_allocator, x._allocator);
			}

			void clear()
			{
				for (size_type i = 0; i < _size ; i++)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}

			allocator_type get_allocator() const { return _allocator; }

	};
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs){ lhs.swap(rhs);}

		/****** OPERATOR OVERLOADS ******/

		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs > rhs) && !(lhs < rhs));
		}

		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){ return (!(lhs == rhs)); }

		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs > rhs));
		}

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		}

		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
};

#endif

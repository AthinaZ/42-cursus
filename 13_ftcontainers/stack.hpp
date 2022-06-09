#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

// https://opensource.apple.com/source/libcpp/libcpp-19/include/stack.auto.html

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

		public:
			container_type	_container;

		public:
			explicit stack(const Container& cont = Container()) : _container(cont) {};

			~stack() {};

			stack(const stack &cpy) : _container(cpy._container) {}

			stack& operator=(const stack& other) {
				_container = other._container;
				return *this;
			}

			reference top() {
				return _container.back();
			}

			const_reference top() const {
				return _container.back();
			}

			bool empty() const {
				return _container.empty();
			}

			size_type size() const {
				return _container.size();
			}

			void push(const value_type& value) {
				_container.push_back(value);
			}

			void pop() {
				_container.pop_back();
			}
	};

	template< class T, class Container >
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container == rhs._container;
	}

	template< class T, class Container >
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container != rhs._container;
	}

	template< class T, class Container >
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container < rhs._container;
	}

	template< class T, class Container >
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container <= rhs._container;
	}

	template< class T, class Container >
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container > rhs._container;
	}

	template< class T, class Container >
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._container >= rhs._container;
	}

}

#endif

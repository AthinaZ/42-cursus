#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
//#include <algorithm>
//#include <deque>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() {}
		MutantStack<T> (const MutantStack<T> &copy) {*this = copy;}
		MutantStack<T> &operator = (const MutantStack<T> &op)
		{
			std::stack<T>::operator = (op);
			return *this;
		}
		~MutantStack<T>() {}
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

// https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators

#endif


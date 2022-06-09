#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include "utils.hpp"

// https://www.cplusplus.com/reference/iterator/
// https://opensource.apple.com/source/libcpp/libcpp-19/include/iterator.auto.html

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template<class T>
    struct iterator_traits<const T *> {
        typedef ptrdiff_t						difference_type;
        typedef T								value_type;
        typedef const T*						pointer;
        typedef const T&						reference;
        typedef	random_access_iterator_tag		iterator_category;
    };



	/****** forward iterator ******/

	template <class Iterator>
	class iterator_vector
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						  typename iterator_traits<Iterator>::value_type,
						  typename iterator_traits<Iterator>::difference_type,
						  typename iterator_traits<Iterator>::pointer,
						  typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator current;
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::pointer				pointer;


		iterator_vector() : current(nullptr) {} //nullptr b/c start
		explicit iterator_vector(Iterator x) : current(x) {}

		template <class Up>
		iterator_vector(const iterator_vector<Up> &u) : current(u.base()) {}

		template <class Up>
		iterator_vector &operator = (const iterator_vector<Up> &u) {current = u.base(); return *this;}
		Iterator base() const {return current;}

		reference operator*() const {return *current;} //check
		pointer operator->() const {return &(*current);} //check
		iterator_vector& operator++() {++current; return *this;}
		iterator_vector  operator++(int) {iterator_vector tmp(*this); ++current; return tmp;}
		iterator_vector& operator--() {--current; return *this;}
		iterator_vector  operator--(int) {iterator_vector tmp(*this); --current; return tmp;}
		iterator_vector  operator+ (difference_type n) const {return iterator_vector(current + n);}
		iterator_vector& operator+=(difference_type n) {current += n; return *this;}
		iterator_vector  operator- (difference_type n) const {return iterator_vector(current - n);}
		iterator_vector& operator-=(difference_type n) {current -= n; return *this;}
		reference         operator[](difference_type n) const {return *(*this + n);} //check
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() == y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() < y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() != y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() > y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() >= y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() <= y.base();
	}

	template <class Iterator1, class Iterator2>
	typename iterator_vector<Iterator1>::difference_type
	operator-(const iterator_vector<Iterator1>& x, const iterator_vector<Iterator2>& y)
	{
		return x.base() - y.base();
	}

	template <class Iterator>
	iterator_vector<Iterator>
	operator+(typename iterator_vector<Iterator>::difference_type n, const iterator_vector<Iterator>& x)
	{
		return iterator_vector<Iterator>(x.base() + n);
	}

	/****** reverse iterator ******/
	template <class Iter>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iter>::iterator_category,
						  typename iterator_traits<Iter>::value_type,
						  typename iterator_traits<Iter>::difference_type,
						  typename iterator_traits<Iter>::pointer,
						  typename iterator_traits<Iter>::reference>
	{
		protected:
			Iter current;
		public:
			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::reference			reference;
			typedef typename iterator_traits<Iter>::pointer				pointer;

		reverse_iterator() : current() {}
		explicit reverse_iterator(Iter x) : current(x) {}

		template <class Up>
		reverse_iterator(const reverse_iterator<Up> &u) : current(u.base()) {}

		template <class Up>
		reverse_iterator &operator = (const reverse_iterator<Up> &u) {current = u.base(); return *this;}
		Iter base() const {return current;}

		reference operator*() const {Iter tmp = current; return const_cast<reference>(*--tmp);} // need const_cast to eliminate "binding value of type 'const int' to reference to type 'int' drops 'const' qualifier" error for set rev it in main
		pointer operator->() const {return &(operator*());}

		

		reverse_iterator& operator++() {--current; return *this;}
		reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
		reverse_iterator& operator--() {++current; return *this;}
		reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
		reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(current - n);}
		reverse_iterator& operator+=(difference_type n) {current -= n; return *this;}
		reverse_iterator  operator- (difference_type n) const {return reverse_iterator(current + n);}
		reverse_iterator& operator-=(difference_type n) {current += n; return *this;}
		reference         operator[](difference_type n) const {return *(*this + n);}
	};

	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() == y.base();
	}

	template <class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() > y.base();
	}

	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() != y.base();
	}

	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() < y.base();
	}

	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() <= y.base();
	}

	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return x.base() >= y.base();
	}

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y)
	{
		return y.base() - x.base();
	}

	template <class Iter>
	reverse_iterator<Iter>
	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& x)
	{
		return reverse_iterator<Iter>(x.base() - n);
	}

}

#endif



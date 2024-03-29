#ifndef SET_HPP
#define SET_HPP

#include "tree.hpp"
#include "tree_algo.hpp"

// https://opensource.apple.com/source/libcpp/libcpp-19/include/set.auto.html

namespace ft
{
	template <class _Tp>
	class set_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef Node<_Tp> 					_Node;
		typedef _Node*						nodeptr;
		nodeptr 							current;

		public:
			typedef _Tp                             value_type;
			typedef _Tp&                  			reference;
			typedef const _Tp*						const_pointer;
			typedef const _Tp&						const_reference;

			explicit set_iterator(): current(NULL) {}
			explicit set_iterator(_Node& newnode): current(&newnode) {}
			explicit set_iterator(const _Node& newnode): current((_Node*)&newnode) {}

			set_iterator(nodeptr newptr) : current(newptr) {}
			set_iterator(set_iterator& it): current(NULL) { *this = it; }

			set_iterator(const set_iterator& it): current(NULL) { *this = it; }
			set_iterator& operator=(const _Node& u) { current = u.base(); return *this; }

			nodeptr base() const { return current; }
			const nodeptr	base(){ return current; }
			const_reference operator*() const { return  current->pair; }
			const_pointer operator->() const { return  &(operator*()); }
			set_iterator& operator++()
			{
				current = static_cast<nodeptr>(tree_next(current));
				return *this;
			}
			set_iterator operator++(int)
			{
				set_iterator __t(*this); ++(*this); return __t;
			}
			set_iterator& operator--()
			{
				current = static_cast<nodeptr>(tree_prev(current));
				return *this;
			}
			set_iterator operator--(int)
			{
				set_iterator __t(*this); --(*this); return __t;
			}
		friend
		bool operator==(const set_iterator& __x, const set_iterator& __y)
			{return __x.current == __y.current;}
		friend
		bool operator!=(const set_iterator& __x, const set_iterator& __y)
			{return !(__x == __y);}
		~set_iterator(){}
	};

	template<typename _Key, typename _Compare = std::less<_Key>, class Allocator = std::allocator<_Key> >
	class set
	{
		public:
			typedef _Key     						value_type;
			typedef _Compare						key_compare;
			typedef _Compare 						value_compare;
			typedef Allocator   					allocator_type;
			typedef ft::set_iterator<value_type>	iterator;
			typedef ft::set_iterator<value_type>	const_iterator;

		private:
			typedef __tree<value_type, iterator, const_iterator, key_compare> base;

			base	tree;
		public:
			typedef typename allocator_type::pointer		 				pointer;
			typedef typename allocator_type::const_pointer	 				const_pointer;
			typedef typename allocator_type::reference		 				reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename ft::reverse_iterator<const_iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
			typedef typename base::size_type		 						size_type;
			typedef typename base::difference_type							difference_type;

		/********************************    CONSTRUCTORS    ********************************/

		explicit set(const _Compare& comp = _Compare(), const allocator_type& alloc = allocator_type())
		: tree(key_compare(comp), allocator_type(alloc)) {}

		template< class InputIt >
		set( InputIt first, InputIt last, const _Compare& comp = _Compare(), const Allocator& alloc = Allocator() )
		:  tree(key_compare(comp), typename base::allocator_type(alloc))
		{
			insert(first, last);
		}
		~set(){}
		set( const set& other ) { insert(other.tree.begin(), other.tree.end()); }

		set& operator=(const set &other)
		{
			if (this != &other)
			{
				tree.clear();
				tree.value_comp() = other.tree.value_comp();
				tree.get_alloc() = other.tree.get_alloc();
				insert(other.tree.begin(), other.tree.end());
			}
			return *this;
		}

		/********************************      ITERATOR     ********************************/

		iterator 		begin()	{ return (iterator)tree.begin(); }
		const_iterator 	begin() const { return (iterator)tree.cbegin(); }
		iterator 		end(){	return (iterator)tree.end();}
		const_iterator 	end()   const {	return tree.cend();}

		reverse_iterator 		rbegin() { return (reverse_iterator(tree.end())); }
		const_reverse_iterator 	rbegin() const { return (const_reverse_iterator(tree.cend())); }
		reverse_iterator 		rend() 	{ return (reverse_iterator(tree.begin())); }
		const_reverse_iterator	rend()   const { return (const_reverse_iterator(tree.cbegin())); }


		/********************************      CAPACITY     ********************************/

		bool      empty()    const { return tree.size() == 0; }
		size_type size()     const { return tree.size(); }
		size_type max_size() const { return tree.max_size(); }

		/********************************   	MODIFIERS     ********************************/

		pair<iterator, bool> 	insert(const value_type& v) { return tree.insert(v); }
		iterator 					insert(iterator position, const value_type& v) { return tree.insert(position, v); }
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			for (; first != last; ++first)
				insert(*first);
		}

		void		erase(iterator position) { tree.erase_position(position); }
		size_type 	erase(const value_type& k) { return tree.erase_key(k); }
		void		erase(iterator first, iterator last) { tree.erase_range(first, last); }
		void 		clear() { return tree.clear(); }
		void 		swap (set& x) { return tree.swap(x.tree); }

		/********************************   	OBSERVER    ********************************/

		allocator_type get_allocator() const { return tree.get_alloc(); }
		key_compare    key_comp()      const { return tree.value_comp(); }
		value_compare  value_comp()    const { return value_compare(tree.value_comp()); }

		/********************************    SET OPERATIONS   ********************************/

		iterator 		find(const value_type& k) { return tree.find(k); }
		const_iterator 	find(const value_type& k) const { return tree.find(k); }

		size_type      	count(const value_type& k) const { return tree.count(k); }

		iterator 		lower_bound(const value_type& k) { return (iterator)tree.lower_bound(k); }
		const_iterator 	lower_bound(const value_type& k) const { return (const_iterator)tree.lower_bound(k); }

		iterator 		upper_bound(const value_type& k) { return tree.upper_bound(k); }
		const_iterator 	upper_bound(const value_type& k) const { return tree.upper_bound(k); }


		pair<iterator,iterator>             equal_range(const value_type& k) { return tree.equal_range(k); }
		pair<const_iterator,const_iterator> equal_range(const value_type& k) const { return tree.equal_range(k); }

	};

	template <class _Key, class _Compare, class Allocator>
	bool operator< (const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class _Key, class _Compare, class Allocator>
	bool operator==(const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return x.size() == y.size() && !(x<y) && !(y<x);
	}


	template <class _Key, class _Compare, class Allocator>
	bool operator!=(const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return !(x == y);
	}

	template <class _Key, class _Compare, class Allocator>
	bool operator> (const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return (y < x);
	}

	template <class _Key, class _Compare, class Allocator>
	bool operator>=(const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return !(x < y);
	}

	template <class _Key, class _Compare, class Allocator>
	bool operator<=(const set<_Key, _Compare, Allocator>& x, const set<_Key, _Compare, Allocator>& y)
	{
		return !(y < x);
	}

	template <class _Key, class _Compare, class Allocator>
	void swap (set<_Key, _Compare, Allocator>& x, set<_Key, _Compare, Allocator>& y) { return x.swap(y); }
}

#endif

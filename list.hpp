#ifndef LIST_HPP
# define LIST_HPP

# include <cstdlib>
# include <limits>
# include "shared.hpp"

namespace ft {

	template < class T >
	class list {
		
		private:

			class node;
	
			class node {

				public:

				node () : _data(T()), _next(0), _prev(0) {}
				node (const T & data) : _data(data), _next(0), _prev(0) {}
				node (
					const T & data, list<T>::node* next, list<T>::node* prev
				) : _data(data), _next(next), _prev(prev) {}
				~node () {}

				T		_data;
				node*	_next;
				node*	_prev;
				
			};

			list<T>::node*		_dummy;
			size_type			_size;

		public:

			class iterator;
			class const_iterator;

			class iterator {

				public:

					list<T>::node *_n;

					/* default constructor */
					iterator () : _n(0) {}
					/* value constructor */
					iterator (node* n) : _n(n) {}
					/* copy constructor */
					iterator (const iterator & x) : _n(x._n) {}
					/* assignation overload */
					iterator&	operator=(const iterator & x) {
						_n = x._n;
						return *this;
					}
					/* destructor */
					~iterator () {}
					/* == overload */
					bool		operator==(const iterator & x) const {
						return _n == x._n;
					}
					/* != overload */
					bool		operator!=(const iterator & x) const {
						return _n != x._n;
					}
					bool		operator==(const const_iterator & x) const {
						return _n == x._n;
					}
					/* != overload */
					bool		operator!=(const const_iterator & x) const {
						return _n != x._n;
					}
					/* dereferencing *overload */
					T&			operator*() const {
						return _n->_data;
					}
					/* dereferencing ->overload const */
					T*			operator->() {
						return &(_n->_data);
					}
					/* ++ overload prefix */
					iterator	operator++() {
						_n = _n->_next;
						return *this;
					}
					/* ++ overload postfix */
					iterator	operator++(int) {
						iterator tmp = *this;
						++*this;
						return tmp;
					}
					/* -- overload prefix */
					iterator	operator--() {
						_n = _n->_prev;
						return *this;
					}
					/* -- overload postfix */
					iterator	operator--(int) {
						iterator tmp = *this;
						_n = _n->_prev;
						return tmp;
					}
			};

			class const_iterator {

				public:

					const list<T>::node *_n;

					/* default constructor */
					const_iterator () : _n(0) {}
					/* value constructor */
					const_iterator (node* n) : _n(n) {}
					/* copy constructor */
					const_iterator (const const_iterator & x) : _n(x._n) {}
					/* copy constructor with iterator */
					const_iterator (const iterator & x) : _n(x._n) {}
					/* assignation overload */
					const_iterator&	operator=(const const_iterator & x) {
						_n = x._n;
						return *this;
					}
					/* destructor */
					~const_iterator () {}
					/* == overload */
					bool		operator==(const const_iterator & x) const {
						return _n == x._n;
					}
					/* != overload */
					bool		operator!=(const const_iterator & x) const {
						return _n != x._n;
					}
					/* dereferencing *overload */
					T&			operator*() const {
						return _n->_data;
					}
					/* dereferencing ->overload const */
					T*			operator->() const {
						return &(_n->_data);
					}
					/* ++ overload prefix */
					const_iterator	operator++() {
						_n = _n->_next;
						return *this;
					}
					/* ++ overload postfix */
					const_iterator	operator++(int) {
						const_iterator tmp = *this;
						++*this;
						return tmp;
					}
					/* -- overload prefix */
					const_iterator	operator--() {
						_n = _n->_prev;
						return *this;
					}
					/* -- overload postfix */
					const_iterator	operator--(int) {
						const_iterator tmp = *this;
						_n = _n->_prev;
						return tmp;
					}
			};

			
/* Default constructor */
			explicit list<T> () : _dummy(new node()), _size(0) {
			}

/* Fill constructor */
			explicit list<T> (size_type n, const T & val = T())
				: _dummy(new node()), _size(0) {
				for (unsigned int i = 0; i < n; i++) {
					push_back(val);
				}
			}

/* Range constructor */
			template < class InputIterator >
			list<T> (
				InputIterator first,
				InputIterator last,
				typename enable_if<
					!std::numeric_limits<InputIterator>::is_integer, 
					InputIterator >::type * = 0
			)
				: _dummy(new node()), _size(0) {
				for (InputIterator it = first; it != last; it++) {
					push_back(*it);
				}
			}

/* Copy constructor */
			list<T> (const list<T> & x) : _dummy(new node()), _size(0) {
				list<T>::node* current = x._dummy->_next;
				while (current != x._dummy) {
					push_back(current->_data);
					current = current->_next;
				}
			}

/* Destructor */
			~list<T> () {
				clear();
				delete _dummy;
			}

/* list::assign */
			template < class InputIterator >
			void	assign (
				InputIterator first,
				InputIterator last,
				typename enable_if<
					!std::numeric_limits<InputIterator>::is_integer, 
					InputIterator >::type * = 0
			) {
				clear();
				for (InputIterator it = first; it != last; it++) {
					push_back(*it);
				}			
			}

			void	assign (size_type n, const T & val) {
				clear();
				for (unsigned int i = 0; i < n; i++) {
					push_back(val);
				}
			}

/* list::back */
			T&		back () {
				return (*(_dummy->_prev))._data;
			}

			const T&		back () const {
				return (*(_dummy->_prev))._data;
			}

/* list::begin */

			iterator	begin () {
				list<T>::node *begin_node =
					_dummy->_next ? _dummy->_next : _dummy;
				iterator b(begin_node); 
				return b;
			}

			const_iterator	begin () const {
				list<T>::node *begin_node =
					_dummy->_next ? _dummy->_next : _dummy;
				const_iterator b(begin_node); 
				return b;
			}

/* list::clear */
			void	clear () {
				erase(begin(), end());
			}

/* list::empty */
			bool	empty () const {
				return _size == 0;
			}

/* list::end */

			iterator end () {
				iterator e(_dummy);
				return e;
			}

			const_iterator	end () const {
				const_iterator e(_dummy);
				return e;			
			}

/* list::erase */

			iterator erase (iterator position) {
				return erase(position, ++position);
			}

			iterator erase (iterator first, iterator last) {
				node*	left = first._n->_prev;
				node*	right = last._n;

				if (left == NULL)
					return (iterator(_dummy));

				if (right == _dummy && left == _dummy) {
					_dummy->_next = NULL;
					_dummy->_prev = NULL;
				} else {
					left->_next = right;
					right->_prev = left;
				}

				while (first != last) {
					right = first._n;
					first++;
					delete right;
					_size -= 1;
				}

				return (iterator(right));
			}

/* list::front */
			T&		front () {
				return (*(_dummy->_next))._data;
			}

			const T&		front () const {
				return (*(_dummy->_next))._data;
			}

/* list::insert */
			iterator	insert (iterator position, const T& val) {
				list<T>::node*	right = position._n;
				list<T>::node*	left = position._n->_prev;

				if (left == NULL)
					left = _dummy;	

				list<T>::node* new_node = new list<T>::node(
					val, right, left
				);

				left->_next = new_node;
				right->_prev = new_node;
					
				_size += 1;

				return (iterator(new_node));
			}

/* list::max_size */
			size_type	max_size () const {
				return std::numeric_limits<size_type>::max() / sizeof(list<T>::node);
			}

/* list::pop_back */
			void	pop_back () {
				erase(--end(), end());
			}

/* list::pop_front */
			void	pop_front () {
				erase(begin(), ++begin());
			}

/* list::push_back */
			void	push_back (const T& val) {
				insert(end(), val);
			}

/* list::push_front */
			void	push_front (const T& val) {
				insert(begin(), val);
			}

/* list::resize */
			void	resize (size_type n, T val = T()) {
				if (n < _size) {
					while (n != _size)
						pop_back();
				}
				else if (n > _size) {
					while (n != _size)
						push_back(val);
				}
			}

/* list::size */
			size_type	size () const {
				return _size;
			}
	};
}

#endif

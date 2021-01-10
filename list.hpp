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
			list<T>::node*		_head;
			list<T>::node*		_tail;
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
					T*			operator->() {
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
			explicit list<T> () : _dummy(new node()), _head(0), _tail(0), _size(0) {
			}

/* Fill constructor */
			explicit list<T> (size_type n, const T & val = T())
				: _dummy(new node()), _head(0), _tail(0), _size(0) {
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
				: _dummy(new node()), _head(0), _tail(0), _size(0) {
				for (InputIterator it = first; it != last; it++) {
					push_back(*it);
				}
			}

/* Copy constructor */
			list<T> (const list<T> & x) : _dummy(new node()), _head(0), _tail(0), _size(0) {
				list<T>::node* current = x._head;
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
				return (*_tail)._data;
			}

			const T&		back () const {
				return (*_tail)._data;
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
				while (empty() == false) {
					pop_back();
				}
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

/* list::front */
			T&		front () {
				return (*_head)._data;
			}

			const T&		front () const {
				return (*_head)._data;
			}

/* list::max_size */
			size_type	max_size () const {
				return std::numeric_limits<size_type>::max() / sizeof(list<T>::node);
			}

/* list::pop_back */
			void	pop_back () {
				list<T>::node* node_to_delete = _tail;	

				if (!_tail)
					return ;
				if (_tail->_prev == _dummy) {// then the node to pop is the only node in the container
					_tail = NULL;
					_head = NULL;
				} else {
					_tail = _tail->_prev;
				}
				// dummy node
				_dummy->_prev = _tail;
				_dummy->_next = _head;
				if (_tail)
					_tail->_next = _dummy;
				// dummy node

				delete node_to_delete;
				_size -= 1;
			}

/* list::pop_front */
			void	pop_front () {
				list<T>::node* node_to_delete = _head;	

				if (!_head)
					return ;
				_head = _head->_next;
				// dummy node
				_dummy->_next = _head;
				if (_head)
					_head->_prev = _dummy;
				// dummy node

				delete node_to_delete;
				_size -= 1;			

			}

/* list::push_back */
			void	push_back (const T& val) {
				if (empty()) {
					push_front(val);
				}
				else {
					list<T>::node* new_node = new list<T>::node(
						val, _dummy, _tail
					);

					_tail->_next = new_node;
					_tail = new_node;
					_size += 1;

					// dummy node
					_dummy->_prev = new_node;
					// dummy node
				}
			}

/* list::push_front */
			void	push_front (const T& val) {
				list<T>::node* new_node = new list<T>::node(
					val, _head, _dummy
				);
				
				if (_head)
					_head->_prev = new_node;
				_head = new_node;
				if (!_tail)
					_tail = _head;
				_size += 1;

				// dummy node
				_dummy->_next = new_node;

				if (!_dummy->_prev) {
					_dummy->_prev = new_node;
					new_node->_next = _dummy;
				}
				// dummy node
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

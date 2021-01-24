#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "shared.hpp"

namespace ft {

	template < class T >
	class	vector {

		private:

			size_type	_size;
			size_type	_capacity;
			T*		_a;

		public:
			
			class iterator;
			class const_iterator;

			typedef	ft::reverse_iterator<iterator>		reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class iterator {

				public:

					typedef ptrdiff_t			difference_type;
					typedef ft::random_access_iterator_tag	iterator_category;
					typedef T				value_type;
					typedef T*				pointer;
					typedef T&				reference;

					T*	_p;

			/* vector::iterator::iterator default */
					iterator () : _p(0) {}

			/* vector::iterator::iterator init */
					iterator (T* p) : _p(p) {}

			/* vector::iterator::iterator copy */
					iterator (const iterator & x) : _p(x._p) {}

			/* vector::iterator::operator= */
					iterator&	operator=(const iterator & x) {
						_p = x._p;
						return *this;
					}

			/* vector::iterator::~iterator */
					~iterator () {}

			/* vector::iterator::operator== */
					bool		operator==(const iterator & x) const {
						return _p == x._p;
					}

					bool		operator==(const const_iterator & x) const {
						return _p == x._p;
					}

			/* vector::iterator::operator!= */
					bool		operator!=(const iterator & x) const {
						return _p != x._p;
					}

					bool		operator!=(const const_iterator & x) const {
						return _p != x._p;
					}

			/* vector::iterator::operator* */
					reference			operator*() const {
						return _p;
					}

			/* vector::iterator::operator-> */
					pointer			operator->() const {
						return _p;
					}

			/* vector::iterator::operator++ */
					iterator	operator++() {
						_p = _p->_pext;
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
						_p = _p->_prev;
						return *this;
					}
					/* -- overload postfix */
					iterator	operator--(int) {
						iterator tmp = *this;
						_p = _p->_prev;
						return tmp;
					}
			};

			class const_iterator {

				public:

					typedef ptrdiff_t			difference_type;
					typedef std::bidirectional_iterator_tag	iterator_category;
					typedef T				value_type;
					typedef const T*			pointer;
					typedef const T&			reference;


					const list<T>::node *_p;

					/* default constructor */
					const_iterator () : _p(0) {}
					/* value constructor */
					const_iterator (node* n) : _p(n) {}
					/* copy constructor */
					const_iterator (const const_iterator & x) : _p(x._p) {}
					/* copy constructor with iterator */
					const_iterator (const iterator & x) : _p(x._p) {}
					/* assignation overload */
					const_iterator&	operator=(const const_iterator & x) {
						_p = x._p;
						return *this;
					}
					/* destructor */
					~const_iterator () {}
					/* == overload */
					bool		operator==(const const_iterator & x) const {
						return _p == x._p;
					}
					/* != overload */
					bool		operator!=(const const_iterator & x) const {
						return _p != x._p;
					}
					/* dereferencing *overload */
					reference			operator*() const {
						return _p->_data;
					}
					/* dereferencing ->overload const */
					pointer			operator->() const {
						return &(_p->_data);
					}
					/* ++ overload prefix */
					const_iterator	operator++() {
						_p = _p->_pext;
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
						_p = _p->_prev;
						return *this;
					}
					/* -- overload postfix */
					const_iterator	operator--(int) {
						const_iterator tmp = *this;
						_p = _p->_prev;
						return tmp;
					}
			};

/* vector::typedef */
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

/* vector::vector default */
			explicit vector () : _size(0); _capacity(0), _a(0) {}

/* vector::vector fill */
			explicit vector (size_type n, const value_type& val = value_type()) {
				reserve(n);
				// insert elements
				_size = n;
			}

/* vector::insert */


/* vector::reserve */
			void	reserve (size_type n) {
				if (n > _capacity) {
					T*	old_memory_block = _a;
					T*	new_memory_block = new T[n];

					for (size_type i = 0; i < _size; i++) {
						new_memory_block[i] = old_memory_block[i];
					}

					_capacity = n;
					delete[] old_memory_block; 
				}
			}

	};
}

#endif


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


		/* copy n elements from b and assign them to a */
			void	_arraycpy(T* a, const T* b, size_type n) {
				for (size_type i = 0; i < n; i++) {
					a[i] = b[i];
				}
			}

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

					pointer	_p;

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
						return *_p;
					}

			/* vector::iterator::operator-> */
					pointer			operator->() const {
						return _p;
					}

			/* vector::iterator::operator++ */
					iterator	operator++() {
						++_p;
						return *this;
					}

					iterator	operator++(int) {
						iterator tmp = *this;
						++*this;
						return tmp;
					}

			/* vector::iterator::operator-- */
					iterator	operator--() {
						--_p;
						return *this;
					}

					iterator	operator--(int) {
						iterator tmp = *this;
						--_p;
						return tmp;
					}

			/* vector::iterator::operator+ */
					iterator	operator+(const difference_type& n) const {
						return iterator(_p + n);
					}

					iterator	operator+(const iterator& x) const {
						return iterator(_p + x._p);
					}

					iterator	operator+(const const_iterator& x) const {
						return iterator(_p + x._p);
					}

					difference_type	operator+(const iterator & x) {
						return _p + x._p;
					}

			/* vector::iterator::operator- */
					iterator	operator-(const difference_type& n) const {
						return iterator(_p - n);
					}

					iterator	operator-(const iterator& x) const {
						return iterator(_p - x._p);
					}

					iterator	operator-(const const_iterator& x) const {
						return iterator(_p - x._p);
					}

					difference_type	operator-(const iterator & x) {
						return _p - x._p;
					}

			/* vector::iterator::operator< */
					bool		operator<(const iterator& x) const {
						return _p < x._p;
					}

					bool		operator<(const const_iterator& x) const {
						return _p < x._p;
					}

			/* vector::iterator::operator> */
					bool		operator>(const iterator& x) const {
						return _p > x._p;
					}

					bool		operator>(const const_iterator& x) const {
						return _p > x._p;
					}

			/* vector::iterator::operator<= */
					bool		operator<=(const iterator& x) const {
						return _p <= x._p;
					}

					bool		operator<=(const const_iterator& x) const {
						return _p <= x._p;
					}

			/* vector::iterator::operator>= */
					bool		operator>=(const iterator& x) const {
						return _p >= x._p;
					}

					bool		operator>=(const const_iterator& x) const {
						return _p >= x._p;
					}

			/* vector::iterator::operator+= */
					iterator	operator+=(const difference_type& n){
						_p += n;
						return *this;
					}

			/* vector::iterator::operator-= */
					iterator	operator-=(const difference_type& n) {
						_p -= n;
						return *this;
					}

			/* vector::iterator::operator[] */
					reference	operator[](const difference_type& n) const {
						return _p[n];
					}
			};

			class const_iterator {

				public:

					typedef ptrdiff_t			difference_type;
					typedef ft::random_access_iterator_tag	iterator_category;
					typedef T				value_type;
					typedef const T*			pointer;
					typedef const T&			reference;

					pointer	_p;

			/* vector::const_iterator::const_iterator default */
					const_iterator () : _p(0) {}

			/* vector::const_iterator::const_iterator init */
					const_iterator (T* p) : _p(p) {}

			/* vector::const_iterator::const_iterator copy */
					const_iterator (const iterator & x) : _p(x._p) {}

					const_iterator (const const_iterator & x) : _p(x._p) {}

			/* vector::const_iterator::operator= */
					const_iterator&	operator=(const iterator & x) {
						_p = x._p;
						return *this;
					}

					const_iterator&	operator=(const const_iterator & x) {
						_p = x._p;
						return *this;
					}

			/* vector::const_iterator::~const_iterator */
					~const_iterator () {}

			/* vector::const_iterator::operator== */
					bool		operator==(const iterator & x) const {
						return _p == x._p;
					}

					bool		operator==(const const_iterator & x) const {
						return _p == x._p;
					}

			/* vector::const_iterator::operator!= */
					bool		operator!=(const iterator & x) const {
						return _p != x._p;
					}

					bool		operator!=(const const_iterator & x) const {
						return _p != x._p;
					}

			/* vector::const_iterator::operator* */
					reference			operator*() const {
						return _p;
					}

			/* vector::const_iterator::operator-> */
					pointer			operator->() const {
						return _p;
					}

			/* vector::const_iterator::operator++ */
					const_iterator	operator++() {
						++_p;
						return *this;
					}

					const_iterator	operator++(int) {
						const_iterator tmp = *this;
						++*this;
						return tmp;
					}

			/* vector::const_iterator::operator-- */
					const_iterator	operator--() {
						--_p;
						return *this;
					}

					const_iterator	operator--(int) {
						const_iterator tmp = *this;
						--_p;
						return tmp;
					}

			/* vector::const_iterator::operator+ */
					const_iterator	operator+(const difference_type& n) const {
						return const_iterator(_p + n);
					}

					const_iterator	operator+(const iterator& x) const {
						return const_iterator(_p + x._p);
					}

					const_iterator	operator+(const const_iterator& x) const {
						return const_iterator(_p + x._p);
					}

					difference_type	operator+(const const_iterator & x) {
						return _p + x._p;
					}

			/* vector::const_iterator::operator- */
					const_iterator	operator-(const difference_type& n) const {
						return const_iterator(_p - n);
					}

					const_iterator	operator-(const iterator& x) const {
						return const_iterator(_p - x._p);
					}

					const_iterator	operator-(const const_iterator& x) const {
						return const_iterator(_p - x._p);
					}

					difference_type	operator-(const const_iterator & x) {
						return _p - x._p;
					}

			/* vector::const_iterator::operator< */
					bool		operator<(const iterator& x) const {
						return _p < x._p;
					}

					bool		operator<(const const_iterator& x) const {
						return _p < x._p;
					}

			/* vector::const_iterator::operator> */
					bool		operator>(const iterator& x) const {
						return _p > x._p;
					}

					bool		operator>(const const_iterator& x) const {
						return _p > x._p;
					}

			/* vector::const_iterator::operator<= */
					bool		operator<=(const iterator& x) const {
						return _p <= x._p;
					}

					bool		operator<=(const const_iterator& x) const {
						return _p <= x._p;
					}

			/* vector::const_iterator::operator>= */
					bool		operator>=(const iterator& x) const {
						return _p >= x._p;
					}

					bool		operator>=(const const_iterator& x) const {
						return _p >= x._p;
					}

			/* vector::const_iterator::operator+= */
					const_iterator	operator+=(const difference_type& n) {
						_p += n;
						return *this;
					}

			/* vector::iterator::operator-= */
					const_iterator	operator-=(const difference_type& n) {
						_p -= n;
						return *this;
					}

			/* vector::const_iterator::operator[] */
					reference	operator[](const difference_type& n) const {
						return _p[n];
					}
			};

/* vector::typedef */
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

/* vector::vector default */
			explicit vector () : _size(0), _capacity(0), _a(0) {}

/* vector::vector fill */
			explicit vector (size_type n, const value_type& val = value_type())
				: _size(0), _capacity(0), _a(0) {
				insert(_a, n, val);
			}

/* vector::begin */
			iterator	begin () {
				return _a;
			}

			const_iterator	begin () const {
				return _a;
			}

/* vector::end */
			iterator	end () {
				if (_a)
					return _a + _size;
				else
					return _a;
			}

			const_iterator	end () const {
				if (_a)
					return _a + _size;
				else
					return _a;
			}
			

/* vector::insert */
			// compte le nombre d'elements à insérer
			// reserve si l'espace est insuffisant
			// ensuite diviser les sequences d'elements en trois pool
			// 1. Elements positionés avant la position d'insertion
			// 2. Elements positionés après la positon d'insertion
			// 3. Nouveaux elements à insérer
			// decaler part2, copier partie 3 

			void	_array_left_shift (pointer a, size_type len, size_type n) {
				// a b c _ _ _ _ _ _
				// 0 1 2 3 4 5 6 7 8
				for (size_type i = 0; i < len; i++) {
					a[i + n] = a[i];
					//a[i] = 0;
			 	}
			}


			iterator	insert (iterator position, const value_type & val) {
				typename iterator::difference_type	dist = position._p - _a;

				insert(position, 1, val);
				
				return _a + dist; 
			}

			void	insert (iterator position, size_type n, const value_type & val) {
				typename iterator::difference_type	dist;
				typename iterator::difference_type	nright;

				if ((_size + n) > _capacity) {
					if (position._p == NULL)
						dist = 0;	
					else
						dist = position._p - _a;
					
					reserve((_size + n) * 2);
					
					position = _a + dist;
				}
				nright = (_a + _size) - position._p;
				_array_left_shift(position._p, nright, n);	

				for (size_type i = 0; i < n; i++) {
					*position = val;
					position++;
				}

				_size += n;
			}

			template < class InputIterator >
			void	insert (iterator position, InputIterator first, InputIterator last,
					typename enable_if<
						!std::numeric_limits<InputIterator>::is_integer,
						InputIterator 
					>::type * = 0)
				{
				/* if an invalid poistion or range is specified : undefined behavior*/
				typename iterator::difference_type	dist;
				typename iterator::difference_type	n = last - first;

				if ((_size + n) > _capacity) {
					if (position._p == NULL)
						dist = 0;	
					else
						dist = position._p - _a;
					
					reserve((_size + n) * 2);
					
					position = _a + dist;
				}
				
				_array_left_shift(position._p, _size, n);	

				while (first != last) {
					*position = *first;
					first++;
					position++;
				}

				_size += n;
			}

/* vector::reserve */
			void	reserve (size_type n) {
				if (n > _capacity) {
					T*	old_memory_block = _a;
					T*	new_memory_block = new T[n];

					_arraycpy(new_memory_block, old_memory_block, _size);
					// copie les elements dans le nouveau bloc memoire
					_capacity = n;
					// update le var capacity avec la nouvelle capacity
					delete[] old_memory_block;
					// delete l'ancien block mémoire _a
					_a = new_memory_block;
					// fait pointer _a sur le nouveau bloc mémoire
				}
			}

	};
}

#endif


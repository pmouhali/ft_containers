#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "shared.hpp"

namespace ft {

	template < class T >
	class	vector {

		private:

			std::allocator<T>	_allocator;
			size_type		_size;
			size_type		_capacity;
			T*			_a;

		/* C stdlib fake memmove */
			T*		_fake_memmove (T* dest, const T* src, size_type n) {
				size_type i;

				if (dest && src) {
					i = 0;
					if (dest <= src) {
						while (i < n) {
							_allocator.construct(dest + i, src[i]);
							i++;
						}
					} else {
						while (n > 0) {
							_allocator.construct(dest + (n - 1), src[n - 1]);
							n--;
						}
					}
				}
				return (dest);
			}

		/* function in charge of the reallocation strategy */
			size_type	_the_right_amount_of_memory(size_type n) {
				if (_capacity  * 2 <= (_size + n))
					return (_size + n);
				else
					return (_size * 2);
			}

		/* will destroy n elements in received array and deallocate it */
			void	_clean(T* ptr, size_type n, size_type size) {
				for (size_type j = 0; j < n; j++) {
					_allocator.destroy(ptr + j);
				}
				_allocator.deallocate(ptr, size);
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
					iterator (pointer p) : _p(p) {}

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
					typedef const T				value_type;
					typedef const T*			pointer;
					typedef const T&			reference;

					pointer	_p;

			/* vector::const_iterator::const_iterator default */
					const_iterator () : _p(0) {}

			/* vector::const_iterator::const_iterator init */
					const_iterator (pointer p) : _p(p) {}

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
						return *_p;
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
			typedef T		value_type;
			typedef T&		reference;
			typedef const T&	const_reference;
			typedef T*		pointer;
			typedef const T*	const_pointer;
			typedef ptrdiff_t	difference_type;
			typedef size_type	size_type;

/* vector::vector default */
			explicit vector () : _size(0), _capacity(0), _a(0) {}

/* vector::vector fill */
			explicit vector (size_type n, const value_type& val = value_type())
				: _size(0), _capacity(0), _a(0) {
				insert(_a, n, val);
			}

/* vector::vector range */
			template < class InputIterator >
			vector (InputIterator first, InputIterator last,
				typename enable_if<!std::numeric_limits<InputIterator>::is_integer,
					InputIterator>::type * = 0) 
				: _size(0), _capacity(0), _a(0)
			{
				insert(_a, first, last);	
			}

/* vector::vector copy */
			vector (const vector & x) : _size(0), _capacity(0), _a(0) {
				insert(_a, x.begin(), x.end());
			}

/* vector::~vector*/
			~vector () {
				_clean(_a, _size, _capacity);
			}

/* vector::assign */
			template < class InputIterator >
			void	assign (InputIterator first, InputIterator last,
				typename enable_if<
					!std::numeric_limits<InputIterator>::is_integer,
						InputIterator 
					>::type * = 0
			) {
				clear();
				insert(_a, first, last);		
			}

			void	assign (size_type n, const value_type & val) {
				clear();
				insert(_a, n, val);		
			}

/* vector::at */
			reference at (size_type n) {
				if (n >= 0 && n < _size)
					return operator[](n);
				throw std::out_of_range("");
			}

			const_reference at (size_type n) const {
				if (n >= 0 && n < _size)
					return operator[](n);
				throw std::out_of_range("");
			}

/* vector::back */
			reference back () {
				return operator[](_size - 1);
			}

			const_reference back () const {
				return operator[](_size - 1);
			}

/* vector::begin */
			iterator	begin () {
				return _a;
			}

			const_iterator	begin () const {
				return _a;
			}

/* vector::capacity */
			size_type capacity () const {
				return _capacity;
			}

/* vector::clear */
			void	clear () {
				erase(begin(), end());
			}

/* vector::empty */
			bool	empty () const {
				return !_size;
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

/* vector::erase */
			iterator	erase (iterator position) {
				return erase(position, ++position);
			}

			iterator	erase (iterator first, iterator last) {
				typename iterator::difference_type	r = first._p - _a;
				pointer	future;

				future = _allocator.allocate(_capacity);

				/* copy the elements located before the first element to erase */
				_fake_memmove(future, _a, first._p - _a);

				/* copy the elements located after the element to erase */
				_fake_memmove(future + (first._p - _a), last._p, (_a + _size) - last._p);
				size_type tmp = _size - (last._p - first._p);
				
				_clean(_a, _size, _capacity);
			
				_a = future;
				_size = tmp;

				return _a + r;
			}

/* vector::front */
			reference	front () {
				return operator[](0);
			}

			const_reference	front () const {
				return operator[](0);
			}

/* vector::insert */
			
			iterator	insert (iterator position, const value_type & val) {
				typename iterator::difference_type	dist = position._p - _a;

				insert(position, 1, val);
				return _a + dist; 
			}

			void	insert (iterator position, size_type n, const value_type & val) {
				pointer	future;
				size_type future_iterator;

				if ((_size + n) > _capacity) {
					size_type	mems = _the_right_amount_of_memory(n);

					future = _allocator.allocate(mems);
					_capacity = mems;
				} else {
					future = _allocator.allocate(_capacity);
				}

				/* copy the elements located before the insertion position */
				_fake_memmove(future, _a, position._p - _a);

				/* insert elements at position */
				future_iterator = position._p - _a;
				for (size_type i = 0; i < n; i++) {
					_allocator.construct(future + future_iterator, val);
					future_iterator++;
				}

				/* copy the elements located after the insertion position */
				_fake_memmove(future + future_iterator, position._p, (_a + _size) - position._p);
				_clean(_a, _size, _capacity);

				_a = future;
				_size += n;
			}

			template < class InputIterator >
			void	insert (iterator position, InputIterator first, InputIterator last,
					typename enable_if<
						!std::numeric_limits<InputIterator>::is_integer,
						InputIterator 
					>::type * = 0)
			{
				pointer	future;
				size_type future_iterator;
				size_type n = last - first;

				if ((_size + n) > _capacity) {
					size_type	mems = _the_right_amount_of_memory(n);

					future = _allocator.allocate(mems);
					_capacity = mems;
				} else {
					future = _allocator.allocate(_capacity);
				}

				/* copy the elements located before the insertion position */
				_fake_memmove(future, _a, position._p - _a);

				/* insert elements at position */
				future_iterator = position._p - _a;
				while (first < last)
				{
					_allocator.construct(future + future_iterator, *first);
					future_iterator++;
					first++;
				}

				/* copy the elements located after the insertion position */
				_fake_memmove(future + future_iterator, position._p, (_a + _size) - position._p);
				_clean(_a, _size, _capacity);

				_a = future;
				_size += n;
			}

/* vector::max_size */
			size_type max_size () const {
				return std::numeric_limits<size_type>::max() / sizeof(pointer);
			}

/* vector::operator= */
			vector&	  operator= (const vector & x) {
				if (*this != x)
					assign(x.begin(), x.end());

				return *this;
			}

/* vector::operator[] */
			reference operator[] (size_type n) {
				return _a[n];
			}

			const_reference operator[] (size_type n) const {
				return _a[n];
			}

/* vector::pop_back */
			void	pop_back () {
				erase(end() - 1);
			}

/* vector::push_back */
			void	push_back (const value_type & val) {
				insert(end(), val);
			}

/* vector::rbegin */
			reverse_iterator rbegin () {
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin () const {
				return const_reverse_iterator(end());
			}

/* vector::rend */
			reverse_iterator rend () {
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend () const {
				return const_reverse_iterator(begin());
			}

/* vector::reserve */
			void	reserve (size_type n) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity) {
					pointer		old_memory_block = _a;
					pointer		new_memory_block = _allocator.allocate(n);
					size_type	tmp = _size;

					_fake_memmove(new_memory_block, old_memory_block, _size);

					_clean(old_memory_block, _size, _capacity);
					
					_capacity = n;
					_size = tmp;
					_a = new_memory_block;
				}
			}

/* vector::resize */
			void	resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					erase(begin() + n, end());
				} else {
					insert(end(), n - _size, val);
				}
			}

/* vector::size */
			size_type	size () const {
				return _size;
			}

/* vector::swap */
			void	swap (vector & x) {
				size_type	tmp_capacity = _capacity;
				size_type	tmp_size = _size;
				pointer		tmp = _a;

				_a = x._a;
				x._a = tmp;
				_size = x._size;
				x._size = tmp_size;
				_capacity = x._capacity;
				x._capacity = tmp_capacity;
			}

	};

/* non member overload vector::swap */
	template < class T >
	void	swap (vector<T> & x, vector<T> & y) {
		x.swap(y);
	}

/* relational operators */
	template < class T >
	bool operator== (const vector<T> & lhs, const vector<T> & rhs) {
		if (lhs.size() == rhs.size()) {
			typename vector<T>::const_iterator lhs_i = lhs.begin();
			typename vector<T>::const_iterator rhs_j = rhs.end();
			typename vector<T>::const_iterator rhs_i = rhs.begin();

			while (rhs_i < rhs_j) {
				if (*lhs_i != *rhs_i)
					return (false);
				lhs_i++;
				rhs_i++;
			}
			return true;
		}
		return false;
	}

	template < class T >
	bool operator!= (const vector<T> & lhs, const vector<T> & rhs) {
		return !(lhs == rhs);
	}

	template < class T >
	bool operator< (const vector<T> & lhs, const vector<T> & rhs) {
		typename vector<T>::const_iterator        lhs_it = lhs.begin();
		typename vector<T>::const_iterator        lhs_e = lhs.end();
		typename vector<T>::const_iterator        rhs_it = rhs.begin();

		if (lhs == rhs)
			return (false);
		while (lhs_it != lhs_e) {
			if (*rhs_it < *lhs_it)
				return (false);
			else if (*lhs_it < *rhs_it)
				return (true);
			lhs_it++;
			rhs_it++;
		}
		return (lhs_it != rhs_it);
	}

	template < class T >
	bool operator> (const vector<T> & lhs, const vector<T> & rhs) {
		return (rhs < lhs);
	}

	template < class T >
	bool operator<= (const vector<T> & lhs, const vector<T> & rhs) {
		return !(rhs < lhs);
	}

	template < class T >
	bool operator>= (const vector<T> & lhs, const vector<T> & rhs) {
		return !(lhs < rhs);
	}

}

#endif

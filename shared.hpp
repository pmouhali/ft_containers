#ifndef SHARED_HPP
# define SHARED_HPP

# include <limits>
# include <functional>
# include <memory>
# include <cstdlib>
# include <cstddef>
# include <stdexcept>

namespace ft {

	template < bool B, class U = void >
	struct enable_if {};

	template < class V >
	struct enable_if< true, V> { typedef V type; };

	typedef unsigned long size_type;

	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template < typename _iterator >
	class	reverse_iterator {
		
		private:

			_iterator	_base_iterator;

		public:

			typedef _iterator				iterator_type;
			typedef typename iterator_type::difference_type	difference_type;
			typedef typename iterator_type::pointer		pointer;
			typedef typename iterator_type::reference	reference;

			reverse_iterator () : _base_iterator() {}

			explicit reverse_iterator (iterator_type i) : _base_iterator(i) {}

			reverse_iterator (const reverse_iterator & x) 
				: _base_iterator(x._base_iterator) {}

			template < class _base_iter >
			reverse_iterator (const reverse_iterator<_base_iter> & rev_it) 
				: _base_iterator(rev_it._base_iterator) {}

			iterator_type		base () const {
				return _base_iterator;
			}

			reference		operator* () const {
				iterator_type	tmp = _base_iterator;
				return *--tmp;
			}

			reverse_iterator&	operator++ () {
				--_base_iterator;
				return *this;
			}

			reverse_iterator	operator++ (int) {
				reverse_iterator	tmp = *this;
				++(*this);
				return *this;
			}

			reverse_iterator&	operator-- () {
				++_base_iterator;
				return *this;
			}

			reverse_iterator	operator-- (int) {
				reverse_iterator	tmp = *this;
				--(*this);
				return *this;
			}

			pointer			operator-> () const {
				return &(operator*());
			}
	};

	template < class _iterator >
	bool	operator== (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() == rhs.base();
	} 

	template < class _iterator >
	bool	operator!= (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() != rhs.base();
	} 

	template < class _iterator >
	bool	operator< (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() > rhs.base();
	} 

	template < class _iterator >
	bool	operator> (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() < rhs.base();
	} 

	template < class _iterator >
	bool	operator<= (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() >= rhs.base();
	} 

	template < class _iterator >
	bool	operator>= (const reverse_iterator<_iterator>& lhs,
			const reverse_iterator<_iterator>& rhs) {
		return lhs.base() <= rhs.base();
	} 

/* std::pair */

	template <class T1, class T2>
	struct pair {

/* std::pair::attributes */
		T1	first;
		T2	second;

		typedef T1	first_type;
		typedef T2	second_type;

/* std::pair::constructors */

		pair () : first(T1()), second(T2()) {}
		
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)  {}

		pair (const first_type& a, const second_type& b) : first (a), second(b) {}

/* std::pair::operator= */

		pair& operator= (const pair& pr) {
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

/* std::pair::operators */

	template <class T1, class T2>
  	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
  	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
  	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}

/* std::make_pair */

	template <class T1, class T2>
  	pair<T1,T2> make_pair (T1 x, T2 y) {
		return ( pair<T1, T2>(x, y) );
	}

}

#endif

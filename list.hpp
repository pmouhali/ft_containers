#ifndef LIST_HPP
# define LIST_HPP

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

			/* unique predicate */
			bool	_xeqy(T x, T y) {
				return (x == y);
			}

			/* bubblesort */

			template < class Compare >
			void	_bubble_sort (Compare comp) {
				iterator first, second, e;
				
				first = begin();
				second = ++begin();
				e = end();
				while (second != e) {
					
					if (!comp(*first, *second)) {
						splice(first, *this, second);
						first = begin();
						second = ++begin();
					} else {
						first++;
						second++;
					}
				}
			}

			/* quicksort */

			template < class Compare >
			void	_quicksort (node* l, node* h, Compare comp) {
				node*	left = l->_prev;
				node*	right = h->_next;
				
				if (h != _dummy && l != h && l != h->_next) {
					node* p = _partition(l, h, comp);

					l = left->_next;
					h = right->_prev;
				
					_quicksort(l, p->_prev, comp);
					_quicksort(p->_next, h, comp);
				}
			}

			template < class Compare >
			node*	_partition (node* l, node* h, Compare comp) {
				T		pivot = h->_data;
				node*	i = l->_prev;
				node*	tmp;

				for (node* j = l; j != h; j = j->_next) {
					if (comp(j->_data, pivot)) {
						i = i->_next;
						tmp = j->_next;
						splice(iterator(i), *this, iterator(j));
						splice(iterator(tmp), *this, iterator(i));
						tmp = j;
						j = i;
						i = tmp;
					}
				}
				i = i->_next;
				tmp = h->_next;
				splice(iterator(i), *this, iterator(h));
				splice(iterator(tmp), *this, iterator(i));

				return h;
			}

			/* mergesort */

			template < class Compare >
			void	_mergesort_wrapper(Compare comp) {
					node* head = _dummy->_next;
					_dummy->_next->_prev = NULL;
					_dummy->_prev->_next = NULL;

					head = _mergesort(head, comp);

					_dummy->_next = head;
					head->_prev = _dummy;
					while (head->_next != NULL) {
						head = head->_next;
					}
					_dummy->_prev = head;
					head->_next = _dummy;
			}

			template < class Compare >
			node *_merge(node *first, node *second, Compare comp)
			{ 
					if (!first) 
							return second; 
					if (!second) 
							return first; 

					if (comp(first->_data, second->_data)) 
					{ 
							first->_next = _merge(first->_next,second, comp); 
							first->_next->_prev = first; 
							return first; 
					} 
					else
					{ 
							second->_next = _merge(first,second->_next, comp);
							second->_next->_prev = second; 
							return second; 
					} 
			} 

			template < class Compare >
			node *_mergesort(node *head, Compare comp) 
			{ 
					if (!head || !head->_next) 
							return head; 
					node *second = split(head); 

					head = _mergesort(head, comp); 
					second = _mergesort(second, comp); 

					return _merge(head,second, comp); 
			} 

			node *split(node *head) 
			{ 
					node *fast = head,*slow = head; 
					while (fast->_next && fast->_next->_next) 
					{ 
							fast = fast->_next->_next; 
							slow = slow->_next; 
					} 
					node *temp = slow->_next; 
					slow->_next = NULL; 
					return temp; 
			} 

		public:


			class iterator;
			class const_iterator;

/* list::typedefs */
			typedef	ft::reverse_iterator<iterator>		reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class iterator {

				public:

					typedef ptrdiff_t			difference_type;
					typedef ft::bidirectional_iterator_tag	iterator_category;
					typedef T				value_type;
					typedef T*				pointer;
					typedef T&				reference;

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
					bool		operator==(const const_iterator & x) const {
						return _n == x._n;
					}
					/* != overload */
					bool		operator!=(const iterator & x) const {
						return _n != x._n;
					}
					bool		operator!=(const const_iterator & x) const {
						return _n != x._n;
					}
					/* dereferencing *overload */
					reference			operator*() const {
						return _n->_data;
					}
					/* dereferencing ->overload const */
					pointer			operator->() {
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
					
					typedef ptrdiff_t			difference_type;
					typedef std::bidirectional_iterator_tag	iterator_category;
					typedef T				value_type;
					typedef const T*			pointer;
					typedef const T&			reference;


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
					reference			operator*() const {
						return _n->_data;
					}
					/* dereferencing ->overload const */
					pointer			operator->() const {
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
				*this = x;
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
				insert(_dummy, first, last);
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
				return begin_node;
			}

			const_iterator	begin () const {
				list<T>::node *begin_node =
					_dummy->_next ? _dummy->_next : _dummy;
				return begin_node;
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
				return _dummy;
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
					return (_dummy);

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

				return (last);
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

			void		insert (iterator position, size_type n, const T& val) {
				for (size_type i = 0; i < n; i++) {
					insert(position, val);
				}
			}

			template < class InputIterator >
			void		insert (
				iterator position,
				InputIterator first,
				InputIterator last,
				typename enable_if<
					!std::numeric_limits<InputIterator>::is_integer, 
					InputIterator >::type * = 0
			) {
				while (first != last) {
					insert(position, *first);
					first++;
				}
			}

/* list::max_size */
			size_type	max_size () const {
				return std::numeric_limits<size_type>::max() / sizeof(node);
			}

/* list::merge */
			void	merge (list<T> & x) {
				merge(x, std::less_equal<T>());
			}

			template < class Compare >
			void	merge (list<T> & x, Compare comp) {
				iterator	it;
				iterator	e;

				if (!empty() && !x.empty() && &x != this) {
					it = begin();
					e = end();
					while (!x.empty() && it != e) {
						if (comp(x.front(), *it))
							splice(it, x, x.begin());
						else
							it++;
					}
					if (!x.empty())
						splice(end(), x);
				}
				else
					splice(end(), x);
			}

/* list::operator= */
			list<T>&	operator= (const list<T> & x) {
				assign(x.begin(), x.end());

				return *this;
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

/* list::rbegin */
			reverse_iterator	rbegin () {
				return reverse_iterator(end());
			}

			const reverse_iterator	rbegin () const {
				return const_reverse_iterator(end());
			}

/* list::remove */
			void	remove (const T& val) {
				iterator	current = begin();
				iterator 	e = end();
				iterator	to_rm;

				while (current != e) {
					if (*current == val) {
						to_rm = current;
						current++;
						erase(to_rm);
					}
					else
						current++;
				}
			}

/* list::remove_if */
			template < class Predicate >
			void	remove_if (Predicate pred) {
				iterator	current = begin();
				iterator 	e = end();
				iterator	to_rm;

				while (current != e) {
					if (pred(*current)) {
						to_rm = current;
						current++;
						erase(to_rm);
					}
					else
						current++;
				}
			}

/* list::rend */
			reverse_iterator	rend () {
				return reverse_iterator(begin());
			}

			const_reverse_iterator	rend () const {
				return const_reverse_iterator(begin());
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

/* list::reverse */
			void	reverse () {
				if (size() > 1) {
					iterator	i = begin();
					iterator	e = end();
					node*		tmp;

					while (i != e) {
						tmp = i._n->_next;
						i._n->_next = i._n->_prev;
						i._n->_prev = tmp;
						i--;
					}
					tmp = i._n->_next;
					i._n->_next = i._n->_prev;
					i._n->_prev = tmp;
				}
			}

/* list::size */
			size_type	size () const {
				return _size;
			}

/* list::sort */
			void	sort () {
				sort(std::less_equal<T>());
			}

			template < class Compare >
			void	sort (Compare comp) {
				if (empty() == false)
					_quicksort(_dummy->_next, _dummy->_prev, comp);
			}

/* list::splice */
			void	splice(iterator position, list& x) {
				iterator first = x.begin();
				iterator last = x.end();
				
				splice(position, x, first, last);
			}

			void	splice (iterator position, list &x, iterator i) {
				splice(position, x, i, ++i);
			}

			void	splice (iterator position, list& x, iterator first, iterator last) {
				/* si le premier element du range est aussi le deuxieme		*/
				/* le range est vide										*/
				/* si position est aussi last, alors la liste reçue en arg	*/
				/* est aussi *this, et l'opération est inutile				*/
				if (first == last || position == last || position == first)
					return ;

				/* defini les nodes d'extrémités pour chaque liste			*/
				/* et pour la sequence de node, ce qui facilite les manips	*/
				node*	left = position._n->_prev;
				node*	right = position._n;
				node*	x_left = first._n->_prev;
				node*	x_right = last._n;
				node*	x_seq_start = first._n;
				node*	x_seq_end = last._n->_prev;

				/* si le node qui précèdera le premier node de la nouvelle	*/
				/* séquence insérée est null, alors la liste de reception	*/
				/* est vide, set ce node à dummy permet une insertion		*/
				/* valide, voir schema de lsite avec dummy node				*/
				if (left == NULL)
					left = _dummy;
				/* même chose pour la liste qui perds la sequence de node	*/
				if (x_left == NULL)
					x_left = x._dummy;

				/* compte le nombre de node présent dans la séquence		*/
				/* cela doit être fait avant les opérations d'insertion		*/
				/* puisque les itérateurs restent valides mais les liste	*/
				/* auront été modifiées */
				int node_seq_len = 0;
				while (first != last) {
					first++;
					node_seq_len++;
				}

				/* attache la séquence de nodes dans la liste de reception	*/
				left->_next = x_seq_start;
				x_seq_start->_prev = left;
				right->_prev = x_seq_end;
				x_seq_end->_next = right;

				/* répare la liste reçue en paramètre						*/
				/* une séquence d'un ou plusieurs nodes a été retirée		*/
				/* si le node à gauche de la sequence						*/
				/* et le node à droite de la sequence						*/
				/* correspondent tout deux au dummy node de la liste		*/
				/* alors tout les nodes de la liste on été retirés			*/
				/* et il faut reset les pointeur du dummy					*/
				/* pour éviter de créer une boucle infinie					*/
				/* sinon les nodes sont rattachés entre eux					*/
				if (x_left == x._dummy && x_right == x._dummy) {
					x_left->_next = NULL;
					x_right->_prev = NULL;
				} else {
					x_left->_next = x_right;
					x_right->_prev = x_left;
				}

				/* met à jour la taille des deux listes, cette action est	*/
				/* située ici plutôt qu'au niveau du compte en cas de throw	*/
				_size += node_seq_len;
				x._size -= node_seq_len;
			}

/* list::swap */
			void	swap (list<T> & x) {
				if (&x != this) {
					iterator	old_begin = begin();

					splice(old_begin, x, x.begin(), x.end());
					x.splice(x.begin(), *this, old_begin, end());
				}
			}

/* list::unique */

			void	unique () {
				if (_size > 1) {
					iterator e = end();
					iterator current = begin();

					current++;
					while (current != e) {
						if (*current == current._n->_prev->_data) {
							current = erase(current);
						}
						else
							current++;
					}
				}
			}
			

			template < class BinaryPredicate >
			void	unique (BinaryPredicate bpred) {
				if (_size > 1) {
					iterator e = end();
					iterator current = begin();
					
					current++;
					while (current != e) {
						if (bpred(*current, current._n->_prev->_data)) {
							current = erase(current);
						}
						else
							current++;
					}
				}
			}

	};

/* Relational Operators for list */

		template < class T >
		bool operator== (const list<T> & lhs, const list<T> & rhs) {
			if (lhs.size() == rhs.size()) {
				typename list<T>::const_iterator	lhs_it = lhs.begin();	
				typename list<T>::const_iterator	lhs_e = lhs.end();	
				typename list<T>::const_iterator	rhs_it = rhs.begin();	

				while (lhs_it != lhs_e) {
					if (*lhs_it != *rhs_it)
						return (false);
					lhs_it++;
					rhs_it++;
				}
				return (true);
			}
			return (false);
		}

		template < class T >
		bool operator!= (const list<T> & lhs, const list<T> & rhs) {
			return (!(lhs == rhs));
		}

		template < class T >
		bool operator< (const list<T> & lhs, const list<T> & rhs) {
			typename list<T>::const_iterator	lhs_it = lhs.begin();	
			typename list<T>::const_iterator	lhs_e = lhs.end();	
			typename list<T>::const_iterator	rhs_it = rhs.begin();		

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
		bool operator> (const list<T> & lhs, const list<T> & rhs) {
			return (rhs < lhs);
		}

		template < class T >
		bool operator>= (const list<T> & lhs, const list<T> & rhs) {
			return (!(lhs < rhs));
		}

		template < class T >
		bool operator<= (const list<T> & lhs, const list<T> & rhs) {
			return (!(rhs < lhs));
		}

		template < class T >
		void	swap (list<T> & x, list<T> & y) {
			x.swap(y);
		}

}

#endif

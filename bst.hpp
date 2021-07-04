/* BINARY SEARCH TREE */

#ifndef BST_HPP
# define BST_HPP

# include "shared.hpp"

namespace ft {

	template < class T >
	class bst {

//		private:
		public: // TODO: enlever

		class node;

		class node {

			public:

			node (const T & data, node* parent, node* left, node* right)
				: _data(data), _parent(parent), _left(left), _right(right) {}
	
			~node () {}

			T		_data;
			node*	_parent;
			node*	_left;
			node*	_right;
		};

/* bst::attributes  */

		node* _root;
		node* _leftmost;
		node* _rightmost;

/* bst::private_methods */

		void	_clear(node* n) {
			if (n) {
				_clear(n->_right);
				_clear(n->_left);
				delete n;
			}
		}

//		public: TODO: décommenter

		class iterator;

		class iterator {

			/*
			**	[NAME] : goto_next_node
			**
			**	[DESCRIPTION] :
			**
			**	Returns a pointer to the given node's in order successor.
			**	Encapsulate the logic behind binary search tree iteration.
			*/

			node	*goto_next_node (node *c) {
				node	*p;

				if (c == NULL)
					return (NULL);

				if (c->_right != NULL) {
					c = c->_right;
					while (c->_left != NULL)
						c = c->_left;
				}
				else {
					p = c->_parent;
					while (p != NULL && c == p->_right) {
						c = p;
						p = p->_parent;
					}
					c = p;
				}

				return c;
			}

			public:

			node	*_n;

			iterator () : _n(NULL) {}

			iterator (node *n) : _n(n) {}

			iterator (const iterator & x) : _n(x._n) {}

			iterator&	operator=(const iterator & x) {
				_n = x._n;
				return *this;
			}

			~iterator () {}

			iterator	operator++ () {
				_n = goto_next_node(_n);
				return *this;
			}

			iterator	operator++ (int) {
				iterator tmp = *this;
				++*this;
				return tmp;
			}

			bool		operator!= (const iterator & x) {
				return (_n != x._n);
			}

		};

/* bst::default_constructor */

		bst () : _root(NULL), _leftmost(NULL), _rightmost(NULL) {}

/* bst::destructor */
		~bst () {
			clear();
		}

/* bst::begin */
		iterator begin () {
			return _leftmost;
		}

/* bst::clear */
		void	clear () {
			_clear(_root);	
		}

/* bst::end */
		iterator end() {
			return iterator();
		}
	};
}

#endif

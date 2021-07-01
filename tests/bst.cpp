#include <iostream>
#include "../bst.hpp"

int 	main(void) {

	ft::bst<int> tree;

	tree._root = new ft::bst<int>::node(8, NULL, NULL, NULL);
	/* left side assign */
	tree._root->_left = new ft::bst<int>::node(3, tree._root, NULL, NULL);
	tree._root->_left->_left = new ft::bst<int>::node(1, tree._root->_left, NULL, NULL);
	tree._root->_left->_right = new ft::bst<int>::node(6, tree._root->_left, NULL, NULL);

	tree._root->_left->_right->_left = new ft::bst<int>::node(4, tree._root->_left->_right, NULL, NULL);
	tree._root->_left->_right->_right = new ft::bst<int>::node(7, tree._root->_left->_right, NULL, NULL);

	/* right side assign */
	tree._root->_right = new ft::bst<int>::node(10, tree._root, NULL, NULL);
	tree._root->_right->_right = new ft::bst<int>::node(14, tree._root->_right, NULL, NULL);

	tree._root->_right->_right->_left = new ft::bst<int>::node(13, tree._root->_right->_right, NULL, NULL);

	/* mock the leftmost node value */
	tree._leftmost = tree._root->_left->_left;

	/* expectations print */
	std::cout << "expect: 1 3 4 6 7 8 10 13 14\n   got: ";

	/* setup iterator */
	ft::bst<int>::iterator	it = tree.begin();
	ft::bst<int>::iterator	it_end = tree.end();

	while (it != it_end) {
		std::cout << it._n->_data << " ";
		it++;
	}

/*
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";
	it++;
	std::cout << it._n->_data << " ";

	std::cout << std::endl;
*/
}

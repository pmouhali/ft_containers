# include <iostream>
# include "../shared.hpp"

void	tdefault_constructor () {
	ft::pair<char, int> p;

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tinit_constructor () {
	ft::pair<char, int> p('A', 42);

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tcopy_constructor () {
	ft::pair<char, int> b('A', 42);
	ft::pair<char, int> p(b);

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tassignment_operator () {
	ft::pair<char, int> b('A', 42);
	ft::pair<char, int> p;

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
	p = b; 
	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	toperators () {
	ft::pair<char, int> p('A', 42);
	ft::pair<char, int> q('A', 42);
	ft::pair<char, int> r('B', 42);
	ft::pair<char, int> s('B', 43);
	ft::pair<char, int> t;
	ft::pair<char, int> u;


	std::cout << (p == q) << std::endl;
	std::cout << (p == r) << std::endl;
	std::cout << (p == s) << std::endl;
	std::cout << (t == u) << std::endl;

	std::cout << (p != q) << std::endl;
	std::cout << (p != r) << std::endl;
	std::cout << (p != s) << std::endl;
	std::cout << (t != u) << std::endl;

	std::cout << (p < q) << std::endl;
	std::cout << (p < r) << std::endl;
	std::cout << (p < s) << std::endl;
	std::cout << (t < u) << std::endl;

	std::cout << (p > q) << std::endl;
	std::cout << (p > r) << std::endl;
	std::cout << (p > s) << std::endl;
	std::cout << (t > u) << std::endl;

	std::cout << (p <= q) << std::endl;
	std::cout << (p <= r) << std::endl;
	std::cout << (p <= s) << std::endl;
	std::cout << (t <= u) << std::endl;

	std::cout << (p >= q) << std::endl;
	std::cout << (p >= r) << std::endl;
	std::cout << (p >= s) << std::endl;
	std::cout << (t >= u) << std::endl;
}

int	main () {
	tdefault_constructor();
	tinit_constructor();
	tcopy_constructor();
	tassignment_operator();
	toperators();
}

# include <iostream>
# include <functional>
# include <algorithm>
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

void	tmake_pair () {
	ft::pair <int,int> foo;
  	ft::pair <int,int> bar;

  	foo = ft::make_pair (10,20);
  	bar = ft::make_pair (10.5,'A');

  	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

void	tless () {
	int foo[]={10,20,5,15,25};
  	int bar[]={15,10,20};
  
	std::sort (foo, foo+5, ft::less<int>());  // 5 10 15 20 25
  	std::sort (bar, bar+3, ft::less<int>());  //   10 15 20
  	if (std::includes (foo, foo+5, bar, bar+3, ft::less<int>()))
    		std::cout << "foo includes bar.\n";
}

int	main () {
	tdefault_constructor();
	tinit_constructor();
	tcopy_constructor();
	tassignment_operator();
	toperators();
	tmake_pair();
	tless();
}

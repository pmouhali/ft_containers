# include <iostream>
# include <functional>
# include <algorithm>
# include "../shared.hpp"

void	tdefault_constructor () {
	std::pair<char, int> p;

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tinit_constructor () {
	std::pair<char, int> p('A', 42);

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tcopy_constructor () {
	std::pair<char, int> b('A', 42);
	std::pair<char, int> p(b);

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	tassignment_operator () {
	std::pair<char, int> b('A', 42);
	std::pair<char, int> p;

	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
	p = b; 
	std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
}

void	toperators () {
	std::pair<char, int> p('A', 42);
	std::pair<char, int> q('A', 42);
	std::pair<char, int> r('B', 42);
	std::pair<char, int> s('B', 43);
	std::pair<char, int> t;
	std::pair<char, int> u;


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
	std::pair <int,int> foo;
  	std::pair <int,int> bar;

  	foo = std::make_pair (10,20);
  	bar = std::make_pair (10.5,'A');

  	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

void	tless () {
	int foo[]={10,20,5,15,25};
  	int bar[]={15,10,20};
  
	std::sort (foo, foo+5, std::less<int>());  // 5 10 15 20 25
  	std::sort (bar, bar+3, std::less<int>());  //   10 15 20
  	if (std::includes (foo, foo+5, bar, bar+3, std::less<int>()))
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

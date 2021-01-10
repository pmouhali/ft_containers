#ifndef SHARED_HPP
# define SHARED_HPP

namespace ft {

	template < bool B, class U = void >
	struct enable_if {};

	template < class V >
	struct enable_if< true, V> { typedef V type; };

	typedef unsigned long size_type;
}

#endif

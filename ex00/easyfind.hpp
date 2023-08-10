#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>

template<typename T>
typename T::const_iterator easyfind(T const & container, int value) {
	typename T::const_iterator ite =  container.end();
	for (typename T::const_iterator it = container.begin(); it != ite; it++) {
		if (*it == value) {
			return it;
		}
	}
	return ite;
}

#endif
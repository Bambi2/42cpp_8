#include "easyfind.hpp"
#include <list>
#include <vector>


int main() {
	std::list<int> li;
	std::vector<float> vec;

	vec.push_back(12.1);
	vec.push_back(3.14);
	vec.push_back(2.7);
	vec.push_back(1.0);


	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
	li.push_back(4);

	if (easyfind(li, 10) != li.end()) {
		std::cout << "Number was found in a list" << std::endl;
	} else {
		std::cout << "Number was not found in a list" << std::endl;
	}

	if (easyfind(vec, 1) != vec.end()) {
		std::cout << "Number was found in a vector" << std::endl;
	} else {
		std::cout << "Number was not found in a list" << std::endl;
	}
}
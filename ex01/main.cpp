#include "Span.hpp"

int main() {
	std::cout << "----------Span1 with size 5 {6, 3, 9, 11, 17}--------" << std::endl;
	Span sp = Span(5);
	// std::cout << sp.shortestSpan() << std::endl;
	// sp.addManyNumbers(1, 5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(17);
	try {
		sp.addNumber(11);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	

	std::cout << "Span 1 shortest span: " <<  sp.shortestSpan() << std::endl;
	std::cout << "Span 1 longest span: " << sp.longestSpan() << std::endl;

	std::cout << "----------Initializing a vector with some values {6, 2, 0, 800, 24, 1, 37}--------" << std::endl;

	unsigned int numbers[] = {6, 2, 0, 800, 24, 1, 37};
	std::vector<unsigned int> vectorWithNumbers(numbers, numbers + sizeof(numbers) / sizeof(unsigned int));

	std::cout << "BEGIN " << *vectorWithNumbers.begin() << std::endl;

	std::cout << "----------Filling span2 with vector values {6, 2, 0, 800, 24, 1, 37}--------" << std::endl;
	Span sp2 = Span(20000);
	sp2.addManyNumbers(vectorWithNumbers.begin(), vectorWithNumbers.end());


	std::cout << "Span 2 shortest span: " <<  sp2.shortestSpan() << std::endl;
	std::cout << "Span 2 longest span: " << sp2.longestSpan() << std::endl;


	std::cout << "----------Trying to find spans of empty and 1 size --------" << std::endl;
	Span emptySpan(0);
	Span spanWithOneElement(1);

	try {
		std::cout << emptySpan.shortestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << emptySpan.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << spanWithOneElement.shortestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << spanWithOneElement.longestSpan() << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
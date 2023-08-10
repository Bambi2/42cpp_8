#include "Span.hpp"

int main() {
	std::cout << "----------Span with size 5--------" << std::endl;
	Span sp = Span(5);
	// std::cout << sp.shortestSpan() << std::endl;
	// sp.addManyNumbers(1, 5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------Span with size 20000--------" << std::endl;
	
	Span sp2 = Span(20000);
	sp2.addManyNumbers(15, 500);
	sp2.addManyNumbers(11, 500);
	sp2.addManyNumbers(6, 5000);
	sp2.addManyNumbers(1, 3000);
	sp2.addManyNumbers(11, 6000);
	// sp2.addManyNumbers(200, 5000);

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}
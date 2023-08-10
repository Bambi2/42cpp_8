#include "Span.hpp"

Span::Span() {
	std::cout << "Span Default constructor called" << std::endl;
}

Span::Span(const unsigned int n) : n(n) {
	std::cout << "Span with " << this->n << " elements created" << std::endl;
	this->nums.reserve(this->n);
}

Span::Span(Span const & copy) {
	std::cout << "Span Copy constructor called" << std::endl;
	*this = copy;
}

Span::~Span() {
	std::cout << "Span Destructor called" << std::endl;
}

Span& Span::operator=(Span const &rhs) {
	std::cout << "Span assigning operator is called" << std::endl;
	if (this != &rhs) {
		this->n = rhs.n;
		this->nums = rhs.nums;
	}
	return *this;
}

void Span::addNumber(const unsigned int value) {
	if (this->nums.size() < this->n) {
		this->nums.push_back(value);
	} else {
		throw std::out_of_range("You can't add more numbers");
	}
}

unsigned int Span::shortestSpan() {
	if (this->nums.size() <= 1) {
		throw NoSpanCanBeFoundException();
	}

	std::vector<int> tempV(this->nums.size(), 0);
	std::adjacent_difference(this->nums.begin(), this->nums.end(), tempV.begin());
	for (std::vector<int>::iterator iter = tempV.begin(); iter < tempV.end(); iter++) {
		*iter = abs(*iter);
	}

	return *std::min_element(tempV.begin() + 1, tempV.end());
}

unsigned int Span::longestSpan() {
	if (this->nums.size() <= 1) {
		throw NoSpanCanBeFoundException();
	}

	std::vector<int> tempV(this->nums.size(), 0);
	std::adjacent_difference(this->nums.begin(), this->nums.end(), tempV.begin());
	for (std::vector<int>::iterator iter = tempV.begin(); iter < tempV.end(); iter++) {
		*iter = abs(*iter);
	}
	
	return *std::max_element(tempV.begin() + 1, tempV.end());
}
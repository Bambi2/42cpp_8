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

	
	std::vector<unsigned int> sortedNums = this->nums;
	// std::sort(sortedNums.begin(), sortedNums.end());
	for (size_t i = 0; i < sortedNums.size(); ++i) {
		for (size_t j = 0; j < sortedNums.size()-i-1; j++) {
			if (sortedNums[j] > sortedNums[j + 1]) {
				std::swap(sortedNums[j], sortedNums[j + 1]);
			}
		}
	}

	return sortedNums[1]-sortedNums[0];
}

unsigned int Span::longestSpan() {
	if (this->nums.size() <= 1) {
		throw NoSpanCanBeFoundException();
	}

	std::vector<unsigned int> sortedNums = this->nums;
	// std::sort(sortedNums.begin(), sortedNums.end());
	for (size_t i = 0; i < sortedNums.size(); ++i) {
		for (size_t j = 0; j < sortedNums.size()-i-1; j++) {
			if (sortedNums[j] > sortedNums[j + 1]) {
				std::swap(sortedNums[j], sortedNums[j + 1]);
			}
		}
	}

	return sortedNums[sortedNums.size()-1]-sortedNums[0];
}
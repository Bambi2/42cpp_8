#ifndef SPAN_H
#define SPAN_H

#include <list>
#include <vector>
#include <iostream>
#include <exception>
#include <numeric>
#include <algorithm>

class Span {
public:
	class NoSpanCanBeFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span can't be found";
		}
	};

	Span(const unsigned int n);
	Span(Span const & copy);
	~Span();

	Span& operator=(Span const &rhs);

	void addNumber(const unsigned int value);

	template<typename Iterator>
	void addManyNumbers(Iterator begin, Iterator end) {
		int count = 0;
		for (; begin < end; begin++) {
			count++;
		}

		if (nums.size() + count < this->n) {
			nums.insert(numbers.end, begin, end)
		} else {
			throw std::out_of_range("You can't add more numbers");
		}
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();
private:
	std::vector<unsigned int> nums;
	unsigned int n;
	Span();
};

#endif
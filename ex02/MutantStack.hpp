#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	class iterator {
	public:
		iterator() : iter() {};

		iterator(typename std::deque<T>::iterator iter) : iter(iter) {};
		iterator(iterator const & copy) {
			this->iter = copy.iter;
		}
		~iterator() {};
	
		iterator& operator=(iterator const &rhs) {
			if (this != &rhs) {
				this->iter = rhs.iter;
			}
			return *this;
		}

		typename std::deque<T>::iterator operator++() {
			this->iter++;
			return this->iter;
		}

		typename std::deque<T>::iterator operator++(int) {
			typename std::deque<T>::iterator old = this->iter;
			operator++();
			return old;
		}

		typename std::deque<T>::iterator operator--() {
			this->iter--;
			return this->iter;
		}

		typename std::deque<T>::iterator operator--(int) {
			typename std::deque<T>::iterator old = this->iter;
			operator--();
			return old;
		}

		T& operator*() { return *(this->iter); }

		bool operator==(iterator const & rhs) const { return (this->iter == rhs.iter); }
		bool operator!=(iterator const & rhs) const { return !(this->iter == rhs.iter); }
	private:
		typename std::deque<T>::iterator iter;
	};
	
	iterator begin() {
		return iterator(std::begin(this->c));
	}

	iterator end() {
		return iterator(std::end(this->c));
	}

private:
};


#endif
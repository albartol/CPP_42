/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:20 by albartol          #+#    #+#             */
/*   Updated: 2024/11/04 16:13:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _max_elements(1) {}

Span::Span(unsigned int N): _max_elements(N) {}

Span::Span(const Span &other): _max_elements(other._max_elements), _elements(other._elements) {}

Span::~Span(void) {}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		_max_elements = other._max_elements;
		_elements = other._elements;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_elements.size() >= _max_elements)
		throw MaxElementsException();
	_elements.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (_elements.size() + std::distance(start, end) > _max_elements)
		throw MaxElementsException();
	_elements.insert(_elements.end(), start, end);
}
void Span::addNumber(std::list<int>::iterator start, std::list<int>::iterator end) {
	if (_elements.size() + std::distance(start, end) > _max_elements)
		throw MaxElementsException();
	_elements.insert(_elements.end(), start, end);
}
void Span::addNumber(std::deque<int>::iterator start, std::deque<int>::iterator end) {
	if (_elements.size() + std::distance(start, end) > _max_elements)
		throw MaxElementsException();
	_elements.insert(_elements.end(), start, end);
}

/* unsigned int Span::longestSpan(void) {
	if (_elements.size() < 2)
		throw InvalidSpanException();

	std::pair<std::deque<int>::iterator, std::deque<int>::iterator> min_max
		= std::minmax_element(_elements.begin(), _elements.end());

	return *min_max.second - *min_max.first;
} */
unsigned int Span::longestSpan(void) const {
	if (_elements.size() < 2)
		throw InvalidSpanException();
	
	int max = *std::max_element(_elements.begin(), _elements.end());
	int min = *std::min_element(_elements.begin(), _elements.end());

	return max - min;
}

/* unsigned int Span::shortestSpan(void) const {
	if (_elements.size() < 2)
		throw InvalidSpanException();

	int min = std::abs(*_elements.begin() - _elements.at(_elements.size()- 1));
	int temp;
	for (std::deque<int>::const_iterator i = _elements.begin(); i != _elements.end(); i++) {
		for (std::deque<int>::const_iterator n = _elements.begin(); n != _elements.end(); n++) {
			if (i == n)
				continue;
			temp = std::abs(*i - *n);
			if (temp < min)
				min = temp;
			if (min == 0)
				return min;
		}
	}
	return min;
} */
unsigned int Span::shortestSpan(void) const {
	if (_elements.size() < 2)
		throw InvalidSpanException();

	int min = std::abs(_elements.front() - _elements.back());
	int temp;
	for (size_t i = 0; i < _elements.size(); i++) {
		for (size_t n = 0; n < _elements.size(); n++) {
			if (i == n)
				continue;
			temp = std::abs(_elements.at(i) - _elements.at(n));
			if (temp < min)
				min = temp;
			if (min == 0)
				return min;
		}
	}
	return min;
}

const std::vector<int>& Span::getElements(void) const {
	return _elements;
}


std::ostream& operator<<(std::ostream &os, const Span &src) {
	const std::vector<int> &elements = src.getElements();
	for (size_t i = 0; i < elements.size(); i++) {
		os << elements.at(i) << " ";
	}
	return os;
}
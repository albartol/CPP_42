/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:39:36 by albartol          #+#    #+#             */
/*   Updated: 2024/11/23 18:50:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other): _first_data(other._first_data),
	_second_data(other._second_data) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe & PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_first_data = other._first_data;
		_second_data = other._second_data;
	}
	return *this;
}

int	PmergeMe::error(const char *message) {
	std::cerr << RED"Error: " << message << RESET"\n";
	return 1;
}

bool	PmergeMe::parseInput(std::string &input) {
	size_t pos = input.find_first_not_of(' ');
	if (pos == std::string::npos)
		return false;
	std::string	valid("0123456789");
	size_t next_pos;
	unsigned long	num;
	while (pos != std::string::npos) {
		next_pos = input.find_first_of(' ', pos);
		if (next_pos == std::string::npos)
			next_pos = input.size();
		if (next_pos - pos > 10)
			return false;
		for (size_t i = pos; i < next_pos; i++) {
			if (valid.find(input[i]) == std::string::npos)
				return false;
		}
		num = std::strtoul(input.substr(pos, next_pos).c_str(), NULL, 10);
		if (num > INT_MAX)
			return false;
		_first_data.push_back(static_cast<int>(num));
		_second_data.push_back(static_cast<int>(num));
		pos = input.find_first_not_of(' ', next_pos + 1);
	}
	return true;
}

static void	sort_pairs(std::vector<std::pair<int, int> > &pairs) {
	if (pairs.size() <= 1)
		return;
	int	m = pairs.size() / 2;
	std::vector<std::pair<int, int> >	first(pairs.begin(), pairs.begin() + m);
	std::vector<std::pair<int, int> >	second(pairs.begin() + m, pairs.end());

	sort_pairs(first);
	sort_pairs(second);
	
	size_t	i = 0;
	size_t	first_i = 0;
	size_t	second_i = 0;
	while (first_i < first.size() || second_i < second.size()) {

		if (first_i < first.size() && second_i < second.size()) {

			if (first[first_i].second < second[second_i].second)
				pairs[i++] = first[first_i++];
			else
				pairs[i++] = second[second_i++];
			continue;
		}
		if (first_i < first.size())
			pairs[i++] = first[first_i++];
		else if (second_i < second.size())
			pairs[i++] = second[second_i++];
	}
}

clock_t	PmergeMe::sortFirst(void) {
	if (_first_data.size() < 2)
		return clock();

	std::vector<std::pair<int, int> >	pairs;
	int	last_val = -1;
	
	if (_first_data.size() % 2 != 0) {
		last_val = _first_data.back();
		_first_data.pop_back();
	}
	for (size_t i = 0; i < _first_data.size(); i += 2) {
		if (_first_data[i] > _first_data[i + 1])
			std::swap(_first_data[i], _first_data[i + 1]);
		pairs.push_back(std::make_pair(_first_data[i], _first_data[i + 1]));
	}
	sort_pairs(pairs);
	_first_data.clear();
	_first_data.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); i++)
		_first_data.push_back(pairs[i].second);

	std::vector<int>::iterator it;

	for (size_t i = 1; i < pairs.size(); i++) {
		
		it = binary_search<std::vector<int> >
			(pairs[i].first, _first_data.begin(), _first_data.end());
			
		_first_data.insert(it, pairs[i].first);
	}
	if (last_val != -1) {
		
		it = binary_search<std::vector<int> >
			(last_val, _first_data.begin(), _first_data.end());
		
		_first_data.insert(it, last_val);
	}
	return clock();
}

clock_t	PmergeMe::sortSecond(void) {
	if (_second_data.size() < 2)
		return clock();

	std::vector<std::pair<int, int> >	pairs;
	int	last_val = -1;
	
	if (_second_data.size() % 2 != 0) {
		last_val = _second_data.back();
		_second_data.pop_back();
	}
	std::vector<int> temp(_second_data.begin(), _second_data.end());
	for (size_t i = 0; i < temp.size(); i += 2) {
		if (temp[i] > temp[i + 1])
			std::swap(temp[i], temp[i + 1]);
		pairs.push_back(std::make_pair(temp[i], temp[i + 1]));
	}
	sort_pairs(pairs);
	_second_data.clear();
	_second_data.push_back(pairs[0].first);
	for (size_t i = 0; i < pairs.size(); i++)
		_second_data.push_back(pairs[i].second);

	std::list<int>::iterator it;
	
	for (size_t i = 1; i < pairs.size(); i++) {
		
		it = binary_search<std::list<int> >
			(pairs[i].first, _second_data.begin(), _second_data.end());
		
		_second_data.insert(it, pairs[i].first);
	}
	if (last_val != -1) {
		
		it = binary_search<std::list<int> >
			(last_val, _second_data.begin(), _second_data.end());
		
		_second_data.insert(it, last_val);
	}
	return clock();
}

void	PmergeMe::startPmergeMe(std::string input) {
	if (input.empty() || !parseInput(input))
		throw InvalidInput();


	std::cout << "Before: ";
	for (size_t i = 0; i < _first_data.size(); i++)
		std::cout << _first_data[i] <<  " ";
	std::cout << "\n";
	
	clock_t	start_first = clock();
	clock_t first_time = sortFirst();
	
	clock_t	start_second = clock();
	clock_t second_time = sortSecond();

	std::cout << "After: \n\tvector: ";
	for (size_t i = 0; i < _first_data.size(); i++)
		std::cout << _first_data[i] <<  " ";
	std::cout << "\n\tlist: ";
	for (size_t i = 0; i < _first_data.size(); i++)
		std::cout << _first_data[i] <<  " ";
	std::cout << "\n";
	
	std::cout << "Time to process a range of " << _first_data.size()
		<< " elements with [std::vector] : "
		<< static_cast<double>(first_time - start_first)/CLOCKS_PER_SEC * 1000 << "ms\n";
	std::cout << "Time to process a range of " << _second_data.size()
		<< " elements with [std::list] : "
		<< static_cast<double>(second_time - start_second)/CLOCKS_PER_SEC * 1000 << "ms\n";
}

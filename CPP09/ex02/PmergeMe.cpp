/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:39:36 by albartol          #+#    #+#             */
/*   Updated: 2024/11/12 17:47:33 by albartol         ###   ########.fr       */
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
			next_pos = input.size() - 1;
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

clock_t	PmergeMe::sortFirst(void) {
	return clock();
}

clock_t	PmergeMe::sortSecond(void) {
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

	std::cout << "After: ";
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

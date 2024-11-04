/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:55 by albartol          #+#    #+#             */
/*   Updated: 2024/11/04 10:14:05 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other):
	_exangeRate(other._exangeRate), _values(other._values) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exangeRate = other._exangeRate;
		_values = other._values;
	}
	return *this;
}

int	BitcoinExchange::error(const char *message) {
	std::cerr << RED"Error: " << message << RESET"\n";
	return 1;
}

void	BitcoinExchange::startExange(const char *input, const char *database) {
	std::ifstream	input_file(input);
	if (!input_file.is_open())
		return error("Failed to open input file");
	std::ifstream	database_file("data.csv");
	if (!database_file.is_open())
		return error("Failed to open database file");
}

bool	BitcoinExchange::storeFile(std::ifstream &src, storage &mp) {
	std::string	line;

	std::getline(src, line, '\n');
	if (checkFile(src))
		return false;
	if (line.empty()) {
		std::cerr << "Empty\n";
		return false;
	}
	return true;
}

bool	BitcoinExchange::checkFile(std::ifstream &src) const {
	if (src.good() || src.eof())
		return false;
	if (src.bad())
		std::cerr << "Reading operation failed\n";
	else if (src.fail())
		std::cerr << "Format error while reading\n";
	return true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:55 by albartol          #+#    #+#             */
/*   Updated: 2024/11/04 17:52:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::ErrorException::ErrorException(const char *msg): _error(msg) {}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _data(other._data) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

int	BitcoinExchange::error(const char *message) {
	std::cerr << RED"Error: " << message << RESET"\n";
	return 1;
}

void	BitcoinExchange::startExchange(const char *input, const char *database) {
	std::ifstream	input_file(input);
	if (!input_file.is_open())
		throw ErrorException("Failed to open input file");
	std::ifstream	database_file(database);
	if (!database_file.is_open()) {
		input_file.close();
		throw ErrorException("Failed to open database file");
	}
	if (!storeFile(database_file, ',')) {
		input_file.close();
		database_file.close();
		throw ErrorException("Reading database failed");
	}
	database_file.close();
	if (!btc(input_file, '|')) {
		input_file.close();
		throw ErrorException("Reading input file failed");
	}
	input_file.close();
}

std::string	BitcoinExchange::trim(std::string src) const{
	size_t start = src.find_first_not_of(' ');
	size_t end = src.find_last_not_of(' ');
	if (start > 0 || end < src.size() - 1)
		return src.substr(start, (end - start) + 1);
	return src;
}

double	BitcoinExchange::getValue(std::string &value_str) const {
	if (value_str.empty() || (value_str.length() == 1 && !isdigit(value_str[0]))) {
		error(value_str.insert(0, "not a number => ").c_str());
		return -1;
	}
	int is_float = 0;
	for (size_t i = 0; i < value_str.length(); i++)
	{
		if (i > 0 && (value_str[i] == '+' || value_str[i] == '-')) {
			error(value_str.insert(0, "not a number => ").c_str());
			return -1;
		}
		if (value_str[i] == '.' && is_float) {
			error(value_str.insert(0, "not a number => ").c_str());
			return -1;
		}
		if (!isdigit(value_str[i]) && value_str[i] != '.'
			&& value_str[i] != '+' && value_str[i] != '-') {
			error(value_str.insert(0, "not a number => ").c_str());
			return -1;
		}
		if (value_str[i] == '.')
			is_float = 1;
	}
	double value = std::strtod(value_str.c_str(), NULL);
	if (value < 0 || (value == 0 && value_str.length() > 1)) {
		error(value_str.insert(0, "not a positive number => ").c_str());
		return -1;
	}
	if (value > 1000) {
		error(value_str.insert(0, "too large a number => ").c_str());
		return -1;
	}
	return value;
}

std::string BitcoinExchange::getDate(std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		error(date.insert(0, "bad date => ").c_str());
		return "bad date";
	}
	if (std::count(date.begin(), date.end(), '-') != 2) {
		error(date.insert(0, "bad date => ").c_str());
		return "bad date";
	}
	if (std::count_if(date.begin(), date.end(), isdigit) != 8) {
		error(date.insert(0, "bad date => ").c_str());
		return "bad date";
	}
	return date;
}

bool	BitcoinExchange::checkHead(std::string &line, char c, const char *s1 , const char *s2) const {
	std::string	date;
	std::string	value_str;
	size_t	split_pos;

	split_pos = line.find(c);
	if (split_pos >= std::string::npos) {
		error(date.insert(0, "invalid header  => ").c_str());
		return false;
	}
	date = trim(line.substr(0, split_pos));
	if (date != s1) {
		error(date.insert(0, "invalid header  => ").c_str());
		return false;
	}
	value_str = trim(line.substr(split_pos + 1, line.size() - split_pos));
	if (value_str != s2) {
		error(date.insert(0, "invalid header  => ").c_str());
		return false;
	}
	return true;
}

bool	BitcoinExchange::btc(std::ifstream &src, char c) {
	std::string	line;
	std::string	date;
	std::string	key;
	std::string	value_str;
	double	value;
	double	exchange;
	size_t	split_pos;

	std::getline(src, line);
	if (checkFile(src))
		return false;
	if (checkHead(src, c) == false)
		return false;
	while (!src.eof())
	{
		std::getline(src, line);
		if (checkFile(src))
			return false;
		split_pos = line.find(c);
		if (split_pos >= std::string::npos || line.size() < 12)
			error(line.insert(0, "bad input => ").c_str());
		else {
			date = trim(line.substr(0, split_pos));
			value_str = trim(line.substr(split_pos + 1, line.size() - split_pos));
			value = getValue(value_str);
			if (value < 0)
				continue;
			key = getDate(date);
			if (key == "bad date")
				continue;
			exchange = std::strtod(_data[key].c_str(), NULL);
			std::cout << date << " => " << value_str << " = " <<  value * exchange << "\n";
		}
	}
	return true;
}

bool	BitcoinExchange::storeFile(std::ifstream &src, char c) {
	std::string	line;
	std::string	key;
	std::string	value;
	size_t	split_pos;

	while (!src.eof())
	{
		std::getline(src, line);
		if (checkFile(src))
			return false;
		split_pos = line.find(c);
		if (split_pos >= std::string::npos)
			return true;
		else {
			key = line.substr(0, split_pos);
			value = line.substr(split_pos + 1, line.size() - split_pos);
			_data[key] = value;
		}
	}
	return true;
}

bool	BitcoinExchange::checkFile(std::ifstream &src) const {
	if (src.good() || src.eof())
		return false;
	return true;
}

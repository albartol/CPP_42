/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:55 by albartol          #+#    #+#             */
/*   Updated: 2024/11/23 20:10:40 by albartol         ###   ########.fr       */
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

std::string	BitcoinExchange::trimStr(std::string src) const{
	size_t start = src.find_first_not_of(' ');
	if (start == src.npos)
		return src;
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
		if ((i > 0 && (value_str[i] == '+' || value_str[i] == '-'))
			|| (value_str[i] == '.' && is_float)
			|| (!isdigit(value_str[i]) && value_str[i] != '.'
				&& value_str[i] != '+' && value_str[i] != '-')) {
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

bool BitcoinExchange::isLeapYear(const int year) const {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

std::string	BitcoinExchange::dateToStr(const t_date &date) const {
	std::string	date_str(to_string(date.year) + '-');
	if (date.month < 10)
		date_str.append('0' + to_string(date.month) + '-');
	else
		date_str.append(to_string(date.month) + '-');
	if (date.day < 10)
		date_str.append('0' + to_string(date.day));
	else
		date_str.append(to_string(date.day));
	return date_str;
}

t_date BitcoinExchange::getLowerDate(t_date date, int *daysInMonth) const {
	date.day--;
	if (date.day < 1) {
		date.month--;
		if (date.month < 1) {
			date.year--;
			daysInMonth[2] = 28;
			if (isLeapYear(date.year))
				daysInMonth[2] = 29;
			date.month = 12;
		}
		date.day = daysInMonth[date.month];
	}
	return date;
}

std::string BitcoinExchange::getClosestDate(t_date date, int *daysInMonth) const {
	std::string	new_date;
	storage::const_iterator	i = _data.end();
	// t_date	lowest_date = getDateValues(_data.begin()->first);
	while (i == _data.end()) {
		// date.day--;
		// if (date.day < 1) {
		// 	date.month--;
		// 	if (date.month < 1) {
		// 		date.year--;
		// 		if (date.year < lowest_date.year) {
		// 			error("closest date not found in database");
		// 			return BAD_DATE;
		// 		}
		// 		daysInMonth[2] = 28;
		// 		if (isLeapYear(date.year))
		// 			daysInMonth[2] = 29;
		// 		date.month = 12;
		// 	}
		// 	date.day = daysInMonth[date.month];
		// }
		date = getLowerDate(date, daysInMonth);
		new_date = dateToStr(date);
		i = _data.find(new_date);
	}
	return new_date;
}

std::string BitcoinExchange::getDate(std::string &date_str) const {
	if ((date_str.length() != 10 || date_str[4] != '-' || date_str[7] != '-')
		|| (std::count(date_str.begin(), date_str.end(), '-') != 2)
		|| (std::count_if(date_str.begin(), date_str.end(), isdigit) != 8)) {
		error(date_str.insert(0, "bad date => ").c_str());
		return BAD_DATE;
	}

	t_date	date = getDateValues(date_str);
	int	daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(date.year))
		daysInMonth[2] = 29;
	if (date.year < MIN_YEAR || date.year > MAX_YEAR || date.month < 1
		|| date.month > 12 || date.day < 1 || date.day > daysInMonth[date.month]) {
		error(date_str.insert(0, "bad date => ").c_str());
		return BAD_DATE;
	}
	if (_data.find(date_str) != _data.end())
		return date_str;

	if (date_str < _data.begin()->first ) {
		error(date_str.insert(0, "date lower than first entry in database => ").c_str());
		return BAD_DATE;
	}
	// t_date	lowest_date = getDateValues(_data.begin()->first);
	// if ((date.year < lowest_date.year)
	// 	|| (date.month < lowest_date.month && date.year <= lowest_date.year)
	// 	|| (date.day < lowest_date.day && date.month <= lowest_date.month
	// 		&& date.year <= lowest_date.year)) {
	// 	error(date_str.insert(0, "date lower than first entry in database => ").c_str());
	// 	return BAD_DATE;
	// }
	return getClosestDate(date, daysInMonth);
}

t_date	BitcoinExchange::getDateValues(const std::string &date_str) const {
	t_date	date;
	date.year = std::atoi(date_str.c_str());
	date.month = std::atoi(date_str.substr(5, 2).c_str());
	date.day = std::atoi(date_str.substr(8, 2).c_str());
	return date;
}

bool	BitcoinExchange::checkHead(std::string &line, char c, const char *s1 , const char *s2) const {
	std::string	date;
	std::string	value_str;
	size_t	split_pos;

	split_pos = line.find(c);
	if (split_pos >= std::string::npos) {
		error(line.insert(0, "invalid header => ").c_str());
		return false;
	}
	date = trimStr(line.substr(0, split_pos));
	if (date != s1) {
		error(line.insert(0, "invalid header => ").c_str());
		return false;
	}
	value_str = trimStr(line.substr(split_pos + 1, line.size() - split_pos));
	if (value_str != s2) {
		error(line.insert(0, "invalid header => ").c_str());
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

	if (src.peek() == std::fstream::traits_type::eof()) {
		error("Input file is empty");
		return false;
	}
	std::getline(src, line);
	if (checkFile(src))
		return false;
	if (checkHead(line, c, "date", "value") == false)
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
			date = trimStr(line.substr(0, split_pos));
			value_str = trimStr(line.substr(split_pos + 1, line.size() - split_pos));
			value = getValue(value_str);
			if (value < 0)
				continue;
			key = getDate(date);
			if (key == BAD_DATE)
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

	if (src.peek() == std::fstream::traits_type::eof()) {
		error("Database is empty");
		return false;
	}
	std::getline(src, line);
	if (checkFile(src))
		return false;
	if (checkHead(line, c, "date", "exchange_rate") == false)
		return false;
	while (!src.eof())
	{
		std::getline(src, line);
		if (checkFile(src))
			return false;
		split_pos = line.find(c);
		if (split_pos >= std::string::npos)
			continue;
		else {
			key = line.substr(0, split_pos);
			value = line.substr(split_pos + 1, line.size() - split_pos);
			_data[key] = value;
		}
	}
	if (_data.empty()) {
		error("Database is empty");
		return false;
	}
	return true;
}

bool	BitcoinExchange::checkFile(std::ifstream &src) const {
	if (src.good() || src.eof())
		return false;
	// if (src.bad())
	// 	error("Reading operation failed");
	// else if (src.fail())
	// 	error("Logical error while reading");
	return true;
}

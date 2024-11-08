/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:35:05 by albartol          #+#    #+#             */
/*   Updated: 2024/11/08 18:45:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define RED "\033[0;91m"
#define RESET "\033[0m"

# include <exception>
# include <algorithm>
# include <iostream>
# include <fstream>
# include <string>
# include <map>
#include <sstream>

#define MIN_YEAR 2000
#define MAX_YEAR 2100
#define BAD_DATE "bad_date"

typedef std::map<std::string, std::string> storage;

template<class T> std::string	to_string(const T& value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

typedef struct s_date {
	int	year;
	int	month;
	int	day;
	s_date() {
		year = 0;
		month = 0;
		day = 0;
	}
}	t_date;

class BitcoinExchange
{
	private:
		storage	_data;
		bool	storeFile(std::ifstream &, char);
		bool	checkFile(std::ifstream &) const;
		bool	checkHead(std::string &, char, const char *s1, const char *s2) const;
		double	getValue(std::string &) const;
		std::string	getDate(std::string &) const;
		std::string	getClosestDate(t_date, int*) const;
		t_date	getLowerDate(t_date, int*) const;
		t_date	getDateValues(const std::string &) const;
		std::string	dateToStr(const t_date &) const;
		bool	isLeapYear(const int) const;
		bool	btc(std::ifstream &, char);
		std::string	trimStr(std::string) const;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &);
		void	startExchange(const char *input, const char *database);
		static int	error(const char *);
		class ErrorException: public std::exception {
			private:
				const char *_error;
			public:
				ErrorException(const char *);
				virtual const char *what() const throw() {
					return _error;
				}
		};
};

#endif
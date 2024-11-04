/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:35:05 by albartol          #+#    #+#             */
/*   Updated: 2024/11/04 17:51:47 by albartol         ###   ########.fr       */
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

typedef std::map<std::string, std::string> storage;

class BitcoinExchange
{
	private:
		std::map<std::string, std::string>	_data;
		bool	storeFile(std::ifstream &, char);
		bool	checkFile(std::ifstream &) const;
		bool	checkHead(std::string &, char, const char *s1, const char *s2) const;
		double	getValue(std::string &) const;
		std::string	getDate(std::string &) const;
		bool	btc(std::ifstream &, char);
		std::string	trim(std::string) const;
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
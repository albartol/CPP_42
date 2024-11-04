/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:35:05 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 22:07:46 by albartol         ###   ########.fr       */
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
		storage	_exangeRate;
		storage	_values;
		bool	storeFile(std::ifstream &, storage &);
		bool	checkFile(std::ifstream &) const;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &);
		void	startExange(const char *input, const char *database);
		static int	error(const char *);
		class ErrorException: public std::exception {
			virtual const char *what() const throw() {
				return "";
			}
		};
};

#endif
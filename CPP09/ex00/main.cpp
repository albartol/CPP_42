/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:33:16 by albartol          #+#    #+#             */
/*   Updated: 2024/11/04 14:19:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return BitcoinExchange::error("Invalid arguments");
	BitcoinExchange	btc;
	try {
		btc.startExchange(argv[1], "data.csv");
	} catch (std::exception &ex) {
		return BitcoinExchange::error(ex.what());
	}
	return 0;
}
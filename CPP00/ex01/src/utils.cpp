/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:52:11 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 16:22:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phone_book.hpp>

// std::string	uint32_to_string(u_int32_t num)
// {
// 	std::string	result;

// 	if (num == 0)
// 		return ("0");
// 	while (num % 10 || num / 10)
// 	{
// 		result.insert(0, 1, num % 10 + 48);
// 		num = num / 10;
// 	}
// 	return (result);
// }

u_int32_t	string_to_uint32(std::string str)
{
	u_int32_t	result;
	u_int32_t	i;

	i = 0;
	result = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

// std::string	format_table_cell(std::string origin)
// {
// 	std::string	result;
// 	u_int32_t	padding;

// 	result = origin.substr(0, CELL_SIZE);
// 	if (result.length() >= CELL_SIZE)
// 		result[CELL_SIZE - 1] = '.';
// 	else
// 	{
// 		padding = CELL_SIZE - result.length();
// 		result.insert(0, padding, ' ');
// 	}
// 	return (result);
// }

std::string	format_table_cell(std::string origin)
{
	std::string	result;

	result = origin.substr(0, CELL_SIZE);
	if (result.length() >= CELL_SIZE)
		result[CELL_SIZE - 1] = '.';
	return (result);
}

std::string	get_input(std::string message)
{
	std::string	input;

	if (std::cin.eof())
		return (EXIT);
	if (message.empty())
		std::cout << "Write input: ";
	else
		std::cout << message;
	std::cout << GREEN;
	std::getline(std::cin, input);
	std::cout << RESET;
	if (std::cin.eof())
		return (EXIT);
	return (input);
}

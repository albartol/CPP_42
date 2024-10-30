/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:52:43 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 19:07:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <iomanip>

static int check_type(std::string data, t_type_info *type_data)
{
	if (data.empty())
		return EXIT_FAILURE;
	if (data == "-inff" || data == "+inff" || data == "inff" || data == "nanf"
		|| data == "-inf" || data == "+inf" || data == "inf" || data == "nan")
		return type_data->invalid = 1 ,EXIT_SUCCESS;
	if (data.length() == 1)
	{
		if (!isdigit(data[0]))
			type_data->not_num = 1;
		return EXIT_SUCCESS;
	}
	if (data[0] == '+' || data[0] == '-')
		type_data->symbol = 1;
	for (size_t i = 0; i < data.length(); i++)
	{
		if (i > 0 && (data[i] == '+' || data[i] == '-'))
			return EXIT_FAILURE;
		if (data[i] == '.' && !type_data->decimal && i > 0 && i + 1 < data.length())
			type_data->decimal = 1;
		else if (data[i] == '.' && (type_data->decimal || i == 0 || i + 1 == data.length()))
			return EXIT_FAILURE;
		if (data[i] == 'f' && i + 1 == data.length())
		{
			if (data[i - 1] == '.')
				return EXIT_FAILURE;
			type_data->f = 1;
		}
		if (isascii(data[i]) && !isdigit(data[i]) && !(data[i] == '.')
			&& !(data[i] == 'f' && i + 1 == data.length())
			&& !(data[i] == '+' || data[i] == '-'))
			return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static void cast_values(const char * data, t_type_info *type_data, t_values *values)
{
	if (type_data->not_num)
	{
		values->ascii = data[0];
		values->num_i = static_cast<int>(values->ascii);
		values->num_f = static_cast<float>(values->ascii);
		values->num_d = static_cast<double>(values->ascii);
	}
	else if (type_data->f)
	{
		values->num_f = std::strtof(data, NULL);
		values->ascii = static_cast<char>(values->num_f);
		values->num_i = static_cast<int>(values->num_f);
		values->num_d = static_cast<double>(values->num_f);
	}
	else if (!type_data->decimal && !type_data->invalid)
	{
		values->num_i = std::atoi(data);
		values->ascii = static_cast<char>(values->num_i);
		values->num_f = static_cast<float>(values->num_i);
		values->num_d = static_cast<double>(values->num_i);
	}
	else
	{
		values->num_d = std::strtod(data, NULL);
		values->ascii = static_cast<char>(values->num_d);
		values->num_i = static_cast<int>(values->num_d);
		values->num_f = static_cast<float>(values->num_d);
	}
}

void ScalarConverter::convert(const char *data)
{
	t_type_info type_data;
	t_values values;
	
	if (check_type(data, &type_data) || (type_data.f && !type_data.decimal))
	{
		std::cout << "Type conversion of [" << data << "] is imposible.\n";
		return;
	}
	cast_values(data, &type_data, &values);
	std::cout << "char: ";
	if (isprint(values.ascii))
		std::cout << values.ascii << "\n";
	else if (type_data.invalid)
		std::cout << "impossible\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (type_data.invalid)
		std::cout << "impossible\n";
	else
		std::cout << values.num_i << "\n";
	std::cout << std::fixed << "float: " << std::setprecision(1)  << values.num_f << "f\n";
	std::cout << "double: " << std::setprecision(1)  << values.num_d << "\n";
}
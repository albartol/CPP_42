/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:52:43 by albartol          #+#    #+#             */
/*   Updated: 2024/10/15 13:40:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void check_type(std::string data, t_type_info *type_data)
{
	size_t	i = 0;
	while (i < data.length())
	{
		if (data.at(i))

		i++;
	}
}

void ScalarConverter::convert(const char *data)
{
	t_type_info type_data;
	
	check_type(data, &type_data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:39:29 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 12:45:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

typedef struct type_info t_type_info;
typedef struct values t_values;

struct type_info
{
	unsigned int	invalid;
	unsigned int	not_num;
	unsigned int	not_dis;
	unsigned int	symbol;
	unsigned int	decimal;
	unsigned int	f;
	type_info()
	{
		invalid = 0;
		not_num = 0;
		not_dis = 0;
		symbol = 0;
		decimal = 0;
		f = 0;
	}
};

struct values
{
	char	ascii;
	int	num_i;
	float	num_f;
	double	num_d;
	values()
	{
		ascii = 0;
		num_i = 0;
		num_f = 0;
		num_d = 0;
	}
};

class ScalarConverter
{
	public:
		ScalarConverter(void){};
		ScalarConverter(const ScalarConverter& other){(void)other;};
		virtual ~ScalarConverter(void) = 0;
		ScalarConverter& operator= (const ScalarConverter& other){(void)other;return*this;};
		static void convert(const char *data);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:39:29 by albartol          #+#    #+#             */
/*   Updated: 2024/10/15 13:39:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

typedef struct type_info t_type_info;

struct type_info
{
	int	invalid = 0;
	int	letter = 0;
	int	symbol = 0;
	int	decimal = 0;
	int	f = 0;
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
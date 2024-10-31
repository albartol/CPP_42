/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:19:07 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 13:40:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct data Data;

struct data
{
	char	a;
	int	b;
	float	c;
	std::string	d;
};

class Serializer
{
	public:
		Serializer(void);
		Serializer(const Serializer& other);
		virtual ~Serializer(void) = 0;
		Serializer& operator= (const Serializer& other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
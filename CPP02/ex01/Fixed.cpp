/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:38:20 by albartol          #+#    #+#             */
/*   Updated: 2024/05/20 17:12:01 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/types.h>
#include <cmath>
#include "Fixed.hpp"

const int8_t	Fixed::fract_bits = 8;

Fixed::Fixed(void) : integer(0) 
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed & src) : integer(src.integer)
{
	std::cout << "Copy contructor called\n";
}

Fixed & Fixed::operator= (const Fixed & src)
{
	std::cout << "Copy assignment operator called\n";
	integer = src.integer;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (integer);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	integer = raw;
}

Fixed::Fixed(const int value) : integer(value << fract_bits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : integer(value * (1 << fract_bits))
{
	std::cout << "Float constructor called\n";
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(integer) / (1 << fract_bits));
}

// int	Fixed::toInt(void) const
// {
// 	return (integer >> fract_bits);
// }

int	Fixed::toInt(void) const
{
	return (roundf(toFloat()));
}

std::ostream & operator<< (std::ostream & os, const Fixed & src)
{
	os << src.toFloat();
	return os;
}

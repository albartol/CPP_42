/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:38:20 by albartol          #+#    #+#             */
/*   Updated: 2024/05/10 12:18:05 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/types.h>
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

int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	return (integer);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	integer = raw;
}

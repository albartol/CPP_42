/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:38:20 by albartol          #+#    #+#             */
/*   Updated: 2024/05/19 21:50:21 by albartol         ###   ########.fr       */
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

int	Fixed::toInt(void) const
{
	return (integer >> fract_bits);
}

std::ostream & operator<< (std::ostream & os, const Fixed & src)
{
	os << src.toFloat();
	return os;
}

bool	Fixed::operator< (const Fixed & other) const
{
	if (integer < other.integer)
		return true;
	return false;
}

bool	Fixed::operator> (const Fixed & other) const
{
	if (integer > other.integer)
		return true;
	return false;
}

bool	Fixed::operator<= (const Fixed & other) const
{
	if (integer <= other.integer)
		return true;
	return false;
}

bool	Fixed::operator>= (const Fixed & other) const
{
	if (integer >= other.integer)
		return true;
	return false;
}

bool	Fixed::operator== (const Fixed & other) const
{
	if (integer == other.integer)
		return true;
	return false;
}

bool	Fixed::operator!= (const Fixed & other) const
{
	if (integer != other.integer)
		return true;
	return false;
}

Fixed	Fixed::operator+ (const Fixed & other) const
{
	return (toFloat() + other.toFloat());
}

Fixed	Fixed::operator- (const Fixed & other) const
{
	return (toFloat() - other.toFloat());
}

Fixed	Fixed::operator* (const Fixed & other) const
{
	if (integer == 0 || other.integer == 0)
		return (0);
	return (toFloat() * other.toFloat());
}

Fixed	Fixed::operator/ (const Fixed & other) const
{
	if (integer == 0)
		return (0);
	if (other.integer == 0)
	{
		std::cerr << "You cant divide by 0\n";
		return (0);
	}
	return (toFloat() / other.toFloat());
}

Fixed & Fixed::operator++ (void)
{
	integer = integer + 1;
	return (*this);
}

Fixed	Fixed::operator++ (int)
{
	Fixed	old_value(*this);

	integer = integer + 1;
	return (old_value);
}

Fixed & Fixed::operator-- (void)
{
	integer = integer - 1;
	return (*this);
}

Fixed	Fixed::operator-- (int)
{
	Fixed	old_value(*this);

	integer = integer - 1;
	return (old_value);
}

Fixed & Fixed::max(Fixed & src1, Fixed & src2)
{
	if (src1.integer > src2.integer)
		return (src1);
	return (src2);
}

const Fixed & Fixed::max(const Fixed & src1, const Fixed & src2)
{
	if (src1.integer > src2.integer)
		return (src1);
	return (src2);
}

Fixed & Fixed::min(Fixed & src1, Fixed & src2)
{
	if (src1.integer < src2.integer)
		return (src1);
	return (src2);
}

const Fixed & Fixed::min(const Fixed & src1, const Fixed & src2)
{
	if (src1.integer < src2.integer)
		return (src1);
	return (src2);
}

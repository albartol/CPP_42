/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:51:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 20:05:09 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "[Point] Default constructor called\n";
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "[Point] Init constructor called\n";
}

Point::Point(const Point & other) : _x(other._x), _y(other._y)
{
	std::cout << "[Point] Copy contructor called\n";
}

Point Point::operator= (const Point & other)
{
	std::cout << "[Point] Copy assignment operator called\n";
	return (other);
}

Point::~Point(void)
{
	std::cout << "[Point] Destructor called\n";
}

const Fixed	Point::getValX(void) const
{
	return (_x);
}

const Fixed	Point::getValY(void) const
{
	return (_y);
}

Point	Point::vector(const Point & a, const Point & b)
{
	Point	ab((b._x - a._x).toFloat(), (b._y - a._y).toFloat());
	return (ab);
}

Fixed	Point::vectorProduct(const Point & v1, const Point & v2)
{
	return (((v1._x * v2._y) - (v1._y * v2._x)));
}

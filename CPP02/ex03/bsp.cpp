/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:52:04 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 21:10:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	fixed_abs(Fixed val)
{
	if (val < 0)
		val = val * -1;
	return (val);
}

static Fixed	triangle_area(const Point a, const Point b, const Point c)
{
	Point	ab = Point::vector(a, b);
	Point	ac = Point::vector(a, c);
	return (fixed_abs(Point::vectorProduct(ab, ac)) / 2);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	total_area = triangle_area(a, b, c);
	Fixed	part_area = triangle_area(a, b, point);
	if (part_area == 0)
		return false;
	Fixed	parts_area = part_area;
	part_area = triangle_area(a, c, point);
	if (part_area == 0)
		return false;
	parts_area = parts_area + part_area;
	part_area = triangle_area(b, c, point);
	if (part_area == 0)
		return false;
	parts_area = parts_area + part_area;
	if (total_area == parts_area)
		return true;
	return false;
}

static int	triangle_orient(const Point a, const Point b, const Point c)
{
	Point	ab = Point::vector(a, b);
	Point	ac = Point::vector(a, c);
	Fixed	orient = Point::vectorProduct(ab, ac);
	if (orient == 0)
		return (0);
	else if (orient > 0)
		return (1);
	return (-1);
}

bool	bsp_2(const Point a, const Point b, const Point c, const Point point)
{
	int	point_orient = triangle_orient(a, b, point);
	point_orient += triangle_orient(b, c, point);
	point_orient += triangle_orient(c, a, point);
	if (point_orient == 3 || point_orient == -3)
		return true;
	return false;
}

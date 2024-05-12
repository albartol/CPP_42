/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:52:00 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 20:04:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:

		const Fixed	_x;
		const Fixed	_y;

	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Point & other);
		Point operator= (const Point & other);
		~Point(void);
		const Fixed	getValX(void) const;
		const Fixed	getValY(void) const;
		static Point	vector(const Point & a, const Point & b);
		static Fixed	vectorProduct(const Point & v1, const Point & v2);

};

#endif

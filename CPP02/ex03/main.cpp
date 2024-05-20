/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:55:59 by albartol          #+#    #+#             */
/*   Updated: 2024/05/20 17:40:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

bool	bsp(const Point a, const Point b, const Point c, const Point point);
bool	bsp_2(const Point a, const Point b, const Point c, const Point point);


int	main(void)
{
	bool	test = bsp(Point(0, 0), Point(10, 0),
						Point(0, 10), Point(5, 5));
	bool	test_2 = bsp_2(Point(0, 0), Point(10, 0),
						Point(0, 10), Point(5, 4));
	if (test)
		std::cout << RED "bsp: point is inside\n" RESET;
	else
		std::cout << RED "bsp: point is outside\n" RESET;
	if (test_2)
		std::cout << RED "bsp_2: point is inside\n" RESET;
	else
		std::cout << RED "bsp_2: point is outside\n" RESET;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:55:59 by albartol          #+#    #+#             */
/*   Updated: 2024/05/20 17:36:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "b: " << b << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a + b: " << a + b << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a - b: " << a - b << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a * b: " << a * b << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a / b: " << a / b << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a < b: " << (a < b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a <= b: " << (a <= b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a > b: " << (a > b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a >= b: " << (a >= b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a == b: " << (a == b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a != b: " << (a != b) << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "++a: " << ++a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a++: " << a++ << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "++a: " << ++a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a--: " << a-- << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a++: " << a++ << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "--a: " << --a << "\n";
	std::cout << "\n";
	std::cout << std::setw(10) << "a: " << a << "\n";
	std::cout << "\n";
	std::cout << "max (a, b): " << Fixed::max( a, b ) << "\n";
	std::cout << "\n";
	std::cout << "min (a, b): " << Fixed::min( a, b ) << "\n";;
	std::cout << "\n";

	return (0);
}

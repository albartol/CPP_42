/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:55:59 by albartol          #+#    #+#             */
/*   Updated: 2024/05/16 21:06:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "b: " << b << "\n"
		<< std::setw(5) << "a + b: " << a + b << "\n"
		<< std::setw(5) << "a - b: " << a - b << "\n"
		<< std::setw(5) << "a * b: " << a * b << "\n"
		<< std::setw(5) << "a / b: " << a / b << "\n"
		<< std::setw(5) << "++a: " << ++a << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "a++: " << a++ << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "++a: " << ++a << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "a--: " << a-- << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "a++: " << a++ << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< std::setw(5) << "--a: " << --a << "\n"
		<< std::setw(5) << "a: " << a << "\n"
		<< "max (a, b): " << Fixed::max( a, b ) << "\n"
		<< "min (a, b): " << Fixed::min( a, b ) << "\n";

	return (0);
}

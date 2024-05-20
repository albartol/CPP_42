/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:36:00 by albartol          #+#    #+#             */
/*   Updated: 2024/05/20 17:11:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( -10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << "\n";
	std::cout << "d is " << d << "\n";

	std::cout << "a is " << a.toInt() << " as integer\n";
	std::cout << "b is " << b.toInt() << " as integer\n";
	std::cout << "c is " << c.toInt() << " as integer\n";
	std::cout << "d is " << d.toInt() << " as integer\n";

	return (0);
}

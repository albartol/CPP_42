/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:46:55 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 02:43:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>


int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min(a, b) = " << ::min(a, b) << "\n";
	std::cout << "max(a, b) = " << ::max(a, b) << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "min(c, d) = " << ::min(c, d) << "\n";
	std::cout << "max(c, d) = " << ::max(c, d) << "\n";

	return 0;
}
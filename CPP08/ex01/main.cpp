/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:24 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 03:52:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(int argc, char **argv)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	
	std::cout << "Simple test:\n\telements: " << sp << "\n\tshortest span: "
		<< sp.shortestSpan() << "\n\tlongest span: " << sp.longestSpan() << "\n";

	if (argc != 2)
		return 1;

	unsigned int num = std::atoi(argv[1]);

	if (num > 10000000)
		return 1;

	Span test(num);
	std::list<int> elements;

	std::srand(time(NULL));
	for (size_t i = 0; i < num; i++) {
		elements.push_back(std::rand() % (num + 1));
	}
	try {
		std::cout << "Custom test:\n";
		test.addNumber(elements.begin(), elements.end());
		if (num <= 256)
			std::cout << "\telements: " << test << "\n";
		std::cout << "\tshortest span: " << test.shortestSpan()
			<< "\n\tlongest span: " << test.longestSpan() << "\n";
	} catch (std::exception &ex) {
		std::cout << ex.what() << "\n";
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:37:23 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 16:52:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "Array.hpp"

int	main(void)
{
	unsigned int elements_num = 30;
	Array<int> test(elements_num);
	std::cout << "test.size() -> " << test.size() << "\n";

	srand(time(NULL));
	for (unsigned int i = 0; i < elements_num; i++) {
		test[i] = rand();
	}

	Array<int> temp(test);
	std::cout << "temp.size() -> " << temp.size() << "\n";

	for (unsigned int i = 0; i < elements_num; i++) {
		if (temp[i] != test[i]) {
			std::cerr << "FAIL" << std::endl;
			return 1;
		}
	}

	{
		Array<int> test2(temp);
		std::cout << "test2[0] -> " << test2[0] << "\n";
		test2[0] = -1;
		std::cout << "test2[0] -> " << test2[0] << "\n";
	}
	std::cout << "temp[0] -> " << temp[0] << "\n";

	try {
		test[-1] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:58:58 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 02:41:46 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	int	array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int	array_len = sizeof(array) / sizeof(int);
	std::vector<int>	vect(array, array + array_len);
	std::list<int>	lst(array, array + array_len);
	std::deque<int>	dqe(array, array + array_len);

	try {
		easyfind(vect, std::atoi(argv[1]));
		easyfind(lst, std::atoi(argv[1]));
		easyfind(dqe, std::atoi(argv[1]));
	} catch (std::exception &ex) {
		std::cout << ex.what() << "\n";
	}
	return 0;
}
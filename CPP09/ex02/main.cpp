/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:38:53 by albartol          #+#    #+#             */
/*   Updated: 2024/11/12 16:45:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return PmergeMe::error("Invalid arguments");
	PmergeMe	sort;
	try {
		std::string	input(argv[1]);
		for (int i = 2; i < argc; i++) {
			input.append(" ");
			input.append(argv[i]);
		}
		sort.startPmergeMe(input);
	} catch (std::exception &ex) {
		return PmergeMe::error(ex.what());
	}
	return 0;
}
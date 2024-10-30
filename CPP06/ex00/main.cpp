/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:20:41 by albartol          #+#    #+#             */
/*   Updated: 2024/10/15 13:22:26 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1] == "")
	{
		std::cerr << "Not valid arguments\n";
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}

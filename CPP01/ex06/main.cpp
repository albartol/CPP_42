/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:22:24 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 21:03:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	complainer;

	if (argc == 2)
		complainer.filter(argv[1]);
	else
		std::cout << "Harl only complains if there is only one argument\n";
	return (0);
}

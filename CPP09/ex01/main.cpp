/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:10:41 by albartol          #+#    #+#             */
/*   Updated: 2024/11/09 17:26:46 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return RPN::error("Invalid arguments");
	RPN	btc;
	try {
		btc.startRPN(argv[1]);
	} catch (std::exception &ex) {
		return RPN::error(ex.what());
	}
	return 0;
}
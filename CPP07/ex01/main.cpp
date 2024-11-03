/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:09:37 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 02:43:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


void	test(char &a)
{
	a += 1;
}

int	main(void)
{
	char array[] = "123456789";

	std::cout << array << "\n";

	::iter(array, 10, &test);

	std::cout << array << "\n";

	return 0;
}
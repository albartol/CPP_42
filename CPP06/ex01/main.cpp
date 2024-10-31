/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:18:52 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 13:44:39 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	test;
	test.a = 'Y';
	test.b = 456;
	test.c = 76436.67;
	test.d = "Funciona?";
	std::cout << "Data original:\n\tchar: " << test.a << "\n\tint: " << test.b
		<< "\n\tfloat: " << test.c << "\n\tstring: " << test.d << "\n";
	uintptr_t	temp = Serializer::serialize(&test);
	Data*	data_ptr = Serializer::deserialize(temp);
	std::cout << "Data ptr:\n\tchar: " << data_ptr->a << "\n\tint: " << data_ptr->b
		<< "\n\tfloat: " << data_ptr->c << "\n\tstring: " << data_ptr->d << "\n";
	std::cout << "Equal: " << (data_ptr == &test) << "\n";
	return 0;
}

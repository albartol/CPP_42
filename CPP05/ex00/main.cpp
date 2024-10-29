/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:38 by albartol          #+#    #+#             */
/*   Updated: 2024/10/10 22:51:15 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat test0("test0", 149);
	Bureaucrat test1("test1", 2);
	try {Bureaucrat test2("test2", -1);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	try {Bureaucrat test3("test3", 0);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	test0.decrementGrade();
	test1.inrcrementGrade();
	std::cout << test0 << test1;
	try {test0.decrementGrade();}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	try {test1.inrcrementGrade();}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	Bureaucrat test4(test0);
	test0 = test1;
	std::cout << test0 << test1 << test4;
	return 0;
}

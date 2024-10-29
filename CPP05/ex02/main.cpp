/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:38 by albartol          #+#    #+#             */
/*   Updated: 2024/10/12 16:27:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat test0("test0", 149);
	Bureaucrat test1("test1", 2);
	try {AForm test2("test2", 34, -1);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	try {AForm test3("test3", 34, 0);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	AForm test5("form01", 6, 140);
	std::cout << test5;
	test0.signForm(test5);
	test1.signForm(test5);
	std::cout << test5;
	return 0;
}

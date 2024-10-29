/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:38 by albartol          #+#    #+#             */
/*   Updated: 2024/10/11 19:37:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat test0("test0", 149);
	Bureaucrat test1("test1", 2);
	try {Form test2("test2", 34, -1);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	try {Form test3("test3", 34, 0);}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	Form test5("form01", 6, 140);
	std::cout << test5;
	test0.signForm(test5);
	test1.signForm(test5);
	std::cout << test5;
	return 0;
}

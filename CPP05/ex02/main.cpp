/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:38 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::string(NULL);
	Bureaucrat test0("test0", 49);
	ShrubberyCreationForm form0("form0");
	test0.signForm(form0);
	test0.executeForm(form0);
	
	Bureaucrat test1("test1", 49);
	RobotomyRequestForm form1("form1");
	test1.signForm(form1);
	test1.executeForm(form1);
	
	Bureaucrat test2("test2", 49);
	PresidentialPardonForm form2("form2");
	test2.signForm(form2);
	test2.executeForm(form2);
	return 0;
}

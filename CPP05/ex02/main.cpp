/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:38 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 13:32:07 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat test0("test0", 49);
	try {
		ShrubberyCreationForm form0("form0");
		test0.signForm(form0);
		form0.execute(test0);
	}
	catch (std::exception& ex) {std::cout << ex.what() << "\n";}
	return 0;
}

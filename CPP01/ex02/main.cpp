/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:16:54 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 20:25:08 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*brain_ptr = &brain;
	std::string	&brain_ref = brain;

	std::cout << "Brain adress: " << &brain << "\n"
		<< "Brain ptr: " << brain_ptr << "\n"
		<< "Brain ref: " << &brain_ref << "\n"
		<< "Brain value: " << brain << "\n"
		<< "Brain ptr value: " << *brain_ptr << "\n"
		<< "Brain ref value: " << brain_ref << "\n";

	return (0);
}

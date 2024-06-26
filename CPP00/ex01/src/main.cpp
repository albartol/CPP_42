/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 15:55:04 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phone_book.hpp>

int main(void)
{
	PhoneBook	book;
	std::string	input;

	while (true)
	{
		input = get_input(ENTER_COMMAND);
		if (input.empty())
			continue ;
		if (input.compare(ADD) == 0)
			book.add_contact();
		else if (input.compare(SEARCH) == 0)
			book.search_contact();
		else if (input.compare(EXIT) == 0)
			break ;
	}
	return (0);
}

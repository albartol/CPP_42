/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:07:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 00:03:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phone_book.hpp>

static void	phone_book_loop(PhoneBook *book)
{
	std::string	input;

	while (true)
	{
		// std::cout << std::endl;
		input = get_input(ENTER_COMMAND);
		if (input.empty())
			continue ;
		if (input.compare(ADD) == 0)
			book->add_contact();
		else if (input.compare(SEARCH) == 0)
			book->search_contact();
		else if (input.compare(EXIT) == 0)
			break ;
	}
}

int main(void)
{
	PhoneBook	book;
	phone_book_loop(&book);
	return (0);
}

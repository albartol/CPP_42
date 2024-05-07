/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:06:22 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 00:13:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <phone_book.hpp>

PhoneBook::PhoneBook(void) : num_of_rows(0), row_to_edit(0) {}

PhoneBook::~PhoneBook(void)
{
	u_int32_t	i;

	i = 0;
	while (i < num_of_rows)
	{
		delete book[i];
		i++;
	}
}

void	PhoneBook::check_contact() const
{
	std::string	temp;

	temp.clear();
}

void	PhoneBook::add_contact(void)
{
	std::string	input;

	if (num_of_rows < MAX_CONTACTS)
	{
		book[num_of_rows] = new Contact(num_of_rows);
		num_of_rows++;
	}
	else
	{
		if (row_to_edit >= MAX_CONTACTS)
			row_to_edit = 0;
		book[row_to_edit]->clean_contact();
	}
	input = get_input(GET_FIRST_NAME);
	book[row_to_edit]->set_value(input, FIRST_NAME);
	input = get_input(GET_LAST_NAME);
	book[row_to_edit]->set_value(input, LAST_NAME);
	input = get_input(GET_NICKNAME);
	book[row_to_edit]->set_value(input, NICKNAME);
	input = get_input(GET_PHONE);
	book[row_to_edit]->set_value(input, PHONE);
	input = get_input(GET_SECRET);
	book[row_to_edit]->set_value(input, SECRET);
	check_contact();
	row_to_edit++;
}

void	PhoneBook::display_book(void) const
{
	u_int32_t	i;

	i = 0;
	std::cout << DIV_ROW << INFO_ROW << DIV_ROW  DIV_ROW;
	while (i < num_of_rows)
	{
		book[i]->print_contact_row();
		std::cout << DIV_ROW;
		i++;
	}
	// std::cout << std::endl;
}

void	PhoneBook::display_contact(u_int32_t index) const
{
	if (index >= num_of_rows)
		std::cout << INVALID_INDEX;
	else
		book[index]->print_contact();
}

void	PhoneBook::search_contact(void) const
{
	std::string	input;
	u_int32_t	index;

	display_book();
	if (!num_of_rows)
	{
		std::cout << EMPTY_BOOK;
		return ;
	}
	input = get_input(GET_INDEX);
	index = string_to_uint32(input);
	display_contact(index);
}

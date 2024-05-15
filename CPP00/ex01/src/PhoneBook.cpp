/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:06:22 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 13:50:57 by albartol         ###   ########.fr       */
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

bool	PhoneBook::empty_field(std::string input) const
{
	if (input.empty())
	{
		std::cout << EMPTY_FIELD;
		book[row_to_edit]->clean_contact();
		return (true);
	}
	return (false);
}

bool	PhoneBook::check_phone(std::string phone) const
{
	if (phone.length() > MAX_PHONE_LENGTH)
	{
		std::cout << INVALID_PHONE;
		book[row_to_edit]->clean_contact();
		return (true);
	}
	return (false);
}

bool	PhoneBook::get_values(void)
{
	std::string	input;

	input = get_input(GET_FIRST_NAME);
	if (empty_field(input))
		return (true);
	book[row_to_edit]->set_value(input, FIRST_NAME);
	input = get_input(GET_LAST_NAME);
	if (empty_field(input))
		return (true);
	book[row_to_edit]->set_value(input, LAST_NAME);
	input = get_input(GET_NICKNAME);
	if (empty_field(input))
		return (true);
	book[row_to_edit]->set_value(input, NICKNAME);
	input = get_input(GET_PHONE);
	if (empty_field(input) || check_phone(input))
		return (true);
	book[row_to_edit]->set_value(input, PHONE);
	input = get_input(GET_SECRET);
	if (empty_field(input))
		return (true);
	book[row_to_edit]->set_value(input, SECRET);
	return (false);
}

void	PhoneBook::add_contact(void)
{
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
	if (get_values())
		return ;
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

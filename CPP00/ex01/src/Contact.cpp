/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:05:22 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 15:30:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <phone_book.hpp>

Contact::Contact(void)
{
	fields[FIRST_NAME] = &first_name;
	fields[LAST_NAME] = &last_name;
	fields[NICKNAME] = &nickname;
	fields[PHONE] = &phone;
	fields[SECRET] = &secret;
}

Contact::~Contact(void)
{
	clean_contact();
}

void Contact::clean_contact(void)
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	phone.clear();
	secret.clear();
}

// void Contact::print_contact_row(void) const
// {
// 	std::string	temp_first;
// 	std::string	temp_last;
// 	std::string	temp_nick;

// 	temp_first = format_table_cell(first_name);
// 	temp_last = format_table_cell(last_name);
// 	temp_nick = format_table_cell(nickname);
// 	std::cout << "|" << std::setw (CELL_SIZE) << index << "|" 
// 		<< temp_first << "|"
// 		<< temp_last << "|"
// 		<< temp_nick << "|" << "\n";
// }

void Contact::print_contact_row(void) const
{
	std::string	temp_first;
	std::string	temp_last;
	std::string	temp_nick;

	temp_first = format_table_cell(first_name);
	temp_last = format_table_cell(last_name);
	temp_nick = format_table_cell(nickname);
	std::cout << "|" << std::setw (CELL_SIZE) << index << "|" 
		<< std::setw (CELL_SIZE) << temp_first << "|"
		<< std::setw (CELL_SIZE) << temp_last << "|"
		<< std::setw (CELL_SIZE) << temp_nick << "|" << "\n";
}

void Contact::print_contact(void) const
{
	std::cout << "First name: " << first_name << "\n"
		<< "Last name: " << last_name << "\n"
		<< "Nickname: " << nickname << "\n"
		<< "Phone number: " << phone << "\n"
		<< "Darkest secret: " << secret << "\n";
}

void Contact::set_value(std::string value, u_int32_t type)
{
	if (type < 5)
		fields[type]->assign(value);
}

void Contact::set_index(u_int32_t new_index)
{
	index = new_index;
}

std::string Contact::get_value(u_int32_t type) const
{
	if (type < 5)
		return (*fields[type]);
	return (NULL);
}

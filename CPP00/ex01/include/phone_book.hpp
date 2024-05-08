/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:40:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 14:53:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "macros.hpp"
# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string	uint32_to_string(u_int32_t num);
u_int32_t	string_to_uint32(std::string str);
std::string	format_table_cell(std::string origin);
std::string	get_input(std::string message);

#endif
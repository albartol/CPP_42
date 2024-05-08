/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:51:14 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 14:53:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MACROS_HPP
# define MACROS_HPP

# include <string>
# include <sys/types.h>
# include <iostream>
# include <new>

# define ENTER_COMMAND "Enter a command (ADD, SEARCH or EXIT): "

# define ADD "ADD"

# define GET_FIRST_NAME "First name: "
# define GET_LAST_NAME "Last name: "
# define GET_NICKNAME "Nickname: "
# define GET_PHONE "Phone numder: "
# define GET_SECRET "Darkest secret: "
# define EMPTY_FIELD "Empty field\n"
# define INVALID_PHONE "Not a valid phone number\n"

# define SEARCH "SEARCH"

# define INFO_ROW "|     Index|First name| Last name|  Nickname|\n"
# define DIV_ROW "---------------------------------------------\n"
# define EMPTY_BOOK "Empty phonebook\n"
# define GET_INDEX "Select contact index (default: 0): "
# define INVALID_INDEX "Not a valid index\n"

# define EXIT "EXIT"

enum
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE,
	SECRET,
	MAX_CONTACTS = 8,
	CELL_SIZE = 10,
	MAX_PHONE_LENGTH = 16
};

#endif

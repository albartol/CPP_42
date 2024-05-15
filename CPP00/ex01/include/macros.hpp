/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:51:14 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 16:29:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MACROS_HPP
# define MACROS_HPP

# include <string>
# include <sys/types.h>
# include <iostream>
# include <cstdlib>

# define GREEN "\033[1;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

# define ENTER_COMMAND "Enter a command (ADD, SEARCH or EXIT): "

# define ADD "ADD"

# define GET_FIRST_NAME "First name: "
# define GET_LAST_NAME "Last name: "
# define GET_NICKNAME "Nickname: "
# define GET_PHONE "Phone numder: "
# define GET_SECRET "Darkest secret: "

# define EMPTY_FIELD "\033[1;31mEmpty field\n\033[0m"
# define TRY_AGAIN "\033[1;31mTry again\n\033[0m"
# define INVALID_PHONE "\033[1;31mNot a valid phone number\n\033[0m"

# define SEARCH "SEARCH"

# define INFO_ROW "|     Index|First name| Last name|  Nickname|\n"
# define DIV_ROW "---------------------------------------------\n"
# define GET_INDEX "Select contact index (default: 0): "

# define EMPTY_BOOK "\033[1;31mEmpty phonebook\n\033[0m"
# define INVALID_INDEX "\033[1;31mNot a valid index\n\033[0m"

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

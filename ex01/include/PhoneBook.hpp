/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:06:37 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 00:09:12 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "macros.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:

		u_int32_t	num_of_rows;
		u_int32_t	row_to_edit;
		Contact *book[MAX_CONTACTS];

		void	check_contact() const;
		void	display_book(void) const;
		void	display_contact(u_int32_t index) const;

	public:

		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void) const;
};

#endif

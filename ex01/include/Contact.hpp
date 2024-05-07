/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:03:36 by albartol          #+#    #+#             */
/*   Updated: 2024/05/07 23:55:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "macros.hpp"

class Contact
{
	private:

		std::string	row;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
		std::string *fields[5];
		const u_int32_t	index;
	
	public:
	
		Contact(u_int32_t num);
		~Contact(void);
		void	clean_contact(void);
		void	set_value(std::string value, u_int32_t type);
		std::string	get_value(u_int32_t type) const;
		void	print_contact_row(void) const;
		void	print_contact(void) const;
};

#endif

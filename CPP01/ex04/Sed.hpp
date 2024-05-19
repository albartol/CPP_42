/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:53:06 by albartol          #+#    #+#             */
/*   Updated: 2024/05/19 20:57:50 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <fstream>

class	Sed
{
	private:

		const std::string	src_str;
		const std::string	dest_str;
		std::ifstream &src_file;
		std::ofstream &dest_file;
		unsigned int	num_of_changes;
		bool	check_src_file(void) const;
		bool	check_dest_file(void) const;
		bool	find_insert(std::string &file);

	public:

		Sed(std::string s1, std::string s2,
			std::ifstream &src, std::ofstream &dest);
		~Sed(void);
		bool	read_replace(void);
		unsigned int	get_changes(void) const;

};

#endif

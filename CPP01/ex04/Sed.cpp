/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:53:04 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 13:13:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(std::string s1, std::string s2, std::ifstream &src,
	std::ofstream &dest) : src_str(s1), dest_str(s2), src_file(src),
	dest_file(dest) {}

Sed::~Sed(void) {}

bool	Sed::read_replace_line(void) const
{
	std::string	line;

	if (check_src_file())
		return false;
	std::getline(src_file, line);
	if (check_src_file())
		return false;
	if (check_dest_file())
		return false;
	if (line.compare(src_str) == 0)
		dest_file << dest_str << "\n";
	else
		dest_file << line << "\n";
	if (check_dest_file())
		return false;
	if (src_file.eof())
	{
		std::cout << "Finished reading\n";
		return false;
	}
	return true;
}

bool	Sed::check_src_file(void) const
{
	if (src_file.good() || src_file.eof())
		return false;
	if (src_file.bad())
		std::cout << "Reading operation failed\n";
	else if (src_file.fail())
		std::cout << "Format error while reading\n";
	return true;
}

bool	Sed::check_dest_file(void) const
{
	if (dest_file.good())
		return false;
	if (dest_file.bad())
		std::cout << "Writing operation failed\n";
	else if (dest_file.fail())
		std::cout << "Failure while writing\n";
	return true;
}

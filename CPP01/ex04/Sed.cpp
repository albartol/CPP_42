/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:53:04 by albartol          #+#    #+#             */
/*   Updated: 2024/05/18 21:25:53 by albartol         ###   ########.fr       */
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

// bool	Sed::read_replace_line(void) const
// {
// 	std::string	line;

// 	if (check_src_file())
// 		return false;
// 	std::getline(src_file, line);
// 	if (check_src_file())
// 		return false;
// 	if (check_dest_file())
// 		return false;
// 	if (line.compare(src_str) == 0)
// 		dest_file << dest_str << "\n";
// 	else
// 		dest_file << line << "\n";
// 	if (check_dest_file())
// 		return false;
// 	if (src_file.eof())
// 	{
// 		std::cout << "Finished reading\n";
// 		return false;
// 	}
// 	return true;
// }

bool	Sed::read_replace(void)
{
	std::string	file;

	// file.assign((std::istreambuf_iterator<char>(src_file)),
	// 	std::istreambuf_iterator<char>());
	src_file.seekg(0, std::ios::end);
	if (check_src_file())
		return false;
	file.resize(src_file.tellg());
	src_file.seekg(0, std::ios::beg);
	if (check_src_file())
		return false;
	src_file.read(&file[0], file.size());
	if (check_src_file())
		return false;
	if (file.empty())
	{
		std::cerr << "Failed to store file contents into a string\n";
		return false;
	}
	find_insert(file);
	dest_file << file;
	if (check_dest_file())
		return false;
	return true;
}

bool	Sed::find_insert(std::string &file)
{
	size_t	i;

	i = 0;
	while (i < file.length())
	{
		i = file.find(src_str, i);
		if (i >= file.length())
			return true;
		file.erase(i, src_str.length());
		file.insert(i, dest_str);
		i += dest_str.length();
	}
	return true;
}

bool	Sed::check_src_file(void) const
{
	if (src_file.good() || src_file.eof())
		return false;
	if (src_file.bad())
		std::cerr << "Reading operation failed\n";
	else if (src_file.fail())
		std::cerr << "Format error while reading\n";
	return true;
}

bool	Sed::check_dest_file(void) const
{
	if (dest_file.good())
		return false;
	if (dest_file.bad())
		std::cerr << "Writing operation failed\n";
	else if (dest_file.fail())
		std::cerr << "Failure while writing\n";
	return true;
}

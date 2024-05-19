/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:53:04 by albartol          #+#    #+#             */
/*   Updated: 2024/05/19 21:21:28 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(std::string s1, std::string s2, std::ifstream &src,
	std::ofstream &dest) : src_str(s1), dest_str(s2), src_file(src),
	dest_file(dest), num_of_changes(0) {}

Sed::~Sed(void) {}

// bool	Sed::read_replace(void)
// {
// 	std::string	file((std::istreambuf_iterator<char>(src_file)),
// 		std::istreambuf_iterator<char>());

// 	if (check_src_file())
// 		return false;
// 	if (file.empty())
// 	{
// 		std::cerr << "Empty file\n";
// 		return false;
// 	}
// 	if (src_str.compare(dest_str) != 0)
// 		find_insert(file);
// 	dest_file << file;
// 	if (check_dest_file())
// 		return false;
// 	return true;
// }

// bool	Sed::read_replace(void)
// {
// 	std::string	file;

// 	std::getline(src_file, file, '\0');
// 	if (check_src_file())
// 		return false;
// 	if (file.empty())
// 	{
// 		std::cerr << "Empty file\n";
// 		return false;
// 	}
// 	if (src_str.compare(dest_str) != 0)
// 		find_insert(file);
// 	dest_file << file;
// 	if (check_dest_file())
// 		return false;
// 	return true;
// }

bool	Sed::read_replace(void)
{
	std::string	file;
	size_t	pos;

	num_of_changes = 0;
	src_file.seekg(0, std::ios::end);
	if (check_src_file())
		return false;
	pos = src_file.tellg();
	if (pos == 0)
	{
		std::cerr << "Empty file\n";
		return false;
	}
	file.resize(pos);
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
	if (src_str.compare(dest_str) != 0)
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
		if (i >= std::string::npos)
			return true;
		file.erase(i, src_str.length());
		file.insert(i, dest_str);
		i += dest_str.length();
		num_of_changes++;
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

unsigned int	Sed::get_changes(void) const
{
	return (num_of_changes);
}

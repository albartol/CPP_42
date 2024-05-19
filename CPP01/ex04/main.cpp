/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:22:24 by albartol          #+#    #+#             */
/*   Updated: 2024/05/19 21:52:05 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "Sed.hpp"

static void	search_and_replace(std::string s1, std::string s2,
			std::ifstream &src, std::ofstream &dest)
{
	Sed	reader(s1, s2, src, dest);

	if (reader.read_replace())
		std::cout << "Number of changes: " << reader.get_changes() << '\n';
}

static int	print_error(std::string error)
{
	std::cout << error << "\n";
	return (1);
}

int	main(int argc, char **argv)
{
	std::ifstream	src_file;
	std::ofstream	new_file;
	std::string	new_name;

	if (argc != 4)
		return (print_error("Invalid number of arguments"));
	src_file.open(argv[1]);
	if (!src_file.is_open())
		return (print_error("Failed to open the source file"));
	new_name = argv[1];
	new_name.append(".replace");
	new_file.open(new_name.c_str(), std::ios::trunc);
	if (!new_file.is_open())
	{
		src_file.close();
		return (print_error("Failed to open the .replace file"));
	}
	search_and_replace(argv[2], argv[3], src_file, new_file);
	return (0);
}

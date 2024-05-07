/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:07:23 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 00:23:48 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	print_capital(std::string str)
{
	size_t	i;
	size_t	len;

	len = str.length();
	i = 0;
	while (i < len)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = str[i] - 32;
		i++;
	}
	std::cout << str;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		print_capital(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:22:59 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 20:14:19 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*new_horde;
	const int	zomie_num = 10;
	int	i = 0;

	new_horde = zombieHorde(zomie_num, "partOfTheHorde");
	while (i < zomie_num)
	{
		new_horde[i].announce();
		i++;
	}
	delete[] new_horde;
	return (0);
}

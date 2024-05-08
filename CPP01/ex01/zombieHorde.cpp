/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:48:36 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 20:14:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <new>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*new_horde;
	int	i = 0;

	new_horde = new Zombie[N];
	while (i < N)
	{
		new_horde[i].set_name(name);
		i++;
	}
	return (new_horde);
}

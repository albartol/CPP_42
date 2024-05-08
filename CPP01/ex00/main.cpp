/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:22:59 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 19:45:06 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*new_zombie;

	new_zombie = newZombie("newZombie");
	randomChump("randomChump");
	new_zombie->announce();
	delete new_zombie;
	return (0);
}

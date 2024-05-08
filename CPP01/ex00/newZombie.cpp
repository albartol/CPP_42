/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:23:06 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 19:39:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <new>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*new_zombie;

	new_zombie = new Zombie(name);
	return (new_zombie);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:32:55 by albartol          #+#    #+#             */
/*   Updated: 2024/05/18 20:16:15 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL) {}

HumanB::~HumanB(void)
{
	std::cout << name << " died\n";
}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their ";
	if (weapon == NULL)
		std::cout << "fists\n";
	else
		std::cout << weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:31:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 03:23:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : name(new_name),
	weapon(new_weapon) {}

HumanA::~HumanA(void)
{
	std::cout << name << " died\n";
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

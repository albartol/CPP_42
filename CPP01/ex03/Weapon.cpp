/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:05:37 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 23:30:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) : type("default weapon") {}

Weapon::Weapon(std::string weapon_type) : type(weapon_type) {}

Weapon::~Weapon(void)
{
	std::cout << type << " destroyed\n";
}

void	Weapon::setType(std::string	new_type)
{
	type = new_type;
}

const std::string &	Weapon::getType(void) const
{
	return (type);
}

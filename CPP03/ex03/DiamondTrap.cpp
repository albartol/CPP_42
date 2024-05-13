/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:24:52 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 23:40:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name),
	ScavTrap(name), FragTrap(name)
{
	_name = ClapTrap::_name;
	ClapTrap::_name.append("_clap_name");
	std::cout << "Naming constructor called\nDiamondTrap: [" << _name << "]\n";
}

DiamondTrap::DiamondTrap(void) : ClapTrap(),
	ScavTrap(), FragTrap()
{
	_name = ClapTrap::_name;
	ClapTrap::_name.append("_clap_name");
	std::cout << "Default constructor called\nDiamondTrap: [" << _name << "]\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy.ClapTrap::_name),
	ScavTrap(copy.ClapTrap::_name), FragTrap(copy.ClapTrap::_name)
{
	_name = copy._name;
	_hitPts = copy._hitPts;
	_energyPts = copy._energyPts;
	_attackDmg = copy._attackDmg;
	std::cout << "Copy constructor called\nDiamondTrap: [" << _name << "]\n";
}

DiamondTrap & DiamondTrap::operator= (DiamondTrap &src)
{
	_name = src._name;
	ClapTrap::_name = src.ClapTrap::_name;
	_hitPts = src._hitPts;
	_energyPts = src._energyPts;
	_attackDmg = src._attackDmg;
	std::cout << "Copy assignment operator called\nDiamondTrap: [" << _name << "]\n";
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called\nDiamondTrap: [" << _name << "]\n";
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "I am, DiamondTrap name: [" << _name
		<< "] ClapTrap name: [" << ClapTrap::_name << "]\n";
}

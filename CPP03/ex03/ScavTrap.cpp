/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:17:26 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 13:31:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "Naming constructor called\nScavTrap: [" << _name << "]\n";
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "Default constructor called\nScavTrap: [" << _name << "]\n";
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy._name)
{
	_hitPts = copy._hitPts;
	_energyPts = copy._energyPts;
	_attackDmg = copy._attackDmg;
	std::cout << "Copy constructor called\nScavTrap: [" << _name << "]\n";
}

ScavTrap & ScavTrap::operator= (ScavTrap &src)
{
	_name = src._name;
	_hitPts = src._hitPts;
	_energyPts = src._energyPts;
	_attackDmg = src._attackDmg;
	std::cout << "Copy assignment operator called\nScavTrap: [" << _name << "]\n";
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called\nScavTrap: [" << _name << "]\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPts == 0)
		std::cout << "ScavTrap [" << _name << "] is dead!\n";
	if (_energyPts == 0)
		std::cout << "ScavTrap [" << _name << "] is too tired to attack\n";
	else
	{
		_energyPts = _energyPts - 1;
		std::cout << "ScavTrap [" << _name << "] attacks [" << target
			<< "], causing " << _attackDmg << " points of damage!\n";
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap [" << _name << "] is in gate keeper mode\n";
}

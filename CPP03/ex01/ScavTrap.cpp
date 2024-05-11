/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:17:26 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 17:42:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) _name(name), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	std::cout << "Naming constructor called\nScavTrap: [" << _name << "]\n";
}

ScavTrap::ScavTrap(void) : _name("default name"), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	std::cout << "Default constructor called\nScavTrap: [" << _name << "]\n";
}

ScavTrap::ScavTrap(ScavTrap &copy) : _name(copy._name), _hitPts(copy._hitPts),
	_energyPts(copy._energyPts), _attackDmg(copy._attackDmg)
{
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
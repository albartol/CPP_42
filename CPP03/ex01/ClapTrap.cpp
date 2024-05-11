/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:13:55 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 17:20:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits.h>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	std::cout << "Naming constructor called\nClapTrap: [" << _name << "]\n";
}

ClapTrap::ClapTrap(void) : _name("default name"), _hitPts(10),
	_energyPts(10), _attackDmg(0)
{
	std::cout << "Default constructor called\nClapTrap: [" << _name << "]\n";
}

ClapTrap::ClapTrap(ClapTrap &copy) : _name(copy._name), _hitPts(copy._hitPts),
	_energyPts(copy._energyPts), _attackDmg(copy._attackDmg)
{
	std::cout << "Copy constructor called\nClapTrap: [" << _name << "]\n";
}

ClapTrap & ClapTrap::operator= (ClapTrap &src)
{
	_name = src._name;
	_hitPts = src._hitPts;
	_energyPts = src._energyPts;
	_attackDmg = src._attackDmg;
	std::cout << "Copy assignment operator called\nClapTrap: [" << _name << "]\n";
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called\nClapTrap: [" << _name << "]\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPts == 0)
		std::cout << "ClapTrap [" << _name << "], is too tired to attack\n";
	else
	{
		_energyPts = _energyPts - 1;
		std::cout << "ClapTrap [" << _name << "] attacks [" << target
			<< "], causing " << _attackDmg << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPts)
		_hitPts = 0;
	else
		_hitPts = _hitPts - amount;
	std::cout << "ClapTrap [" << _name << "] takes "
		<< amount << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned long	amount_check;

	if (_energyPts == 0)
		std::cout << "ClapTrap [" << _name << "], is too tired to be repaired\n";
	else
	{
		_energyPts = _energyPts - 1;
		amount_check = _hitPts + amount;
		if (amount_check >= UINT_MAX)
			_hitPts = UINT_MAX;
		else
			_hitPts = _hitPts + amount;
		std::cout << "ClapTrap [" << _name << "] is repaired for "
			<< amount << " hit points!\n";
	}
}

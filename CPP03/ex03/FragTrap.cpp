/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:00:55 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 00:02:12 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPts = 100;
	if (_energyPts == 10)
		_energyPts = 100;
	_attackDmg = 30;
	std::cout << "Naming constructor called\nFragTrap: [" << _name << "]\n";
}

FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPts = 100;
	if (_energyPts == 10)
		_energyPts = 100;
	_attackDmg = 30;
	std::cout << "Default constructor called\nFragTrap: [" << _name << "]\n";
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy._name)
{
	_hitPts = copy._hitPts;
	_energyPts = copy._energyPts;
	_attackDmg = copy._attackDmg;
	std::cout << "Copy constructor called\nFragTrap: [" << _name << "]\n";
}

FragTrap & FragTrap::operator= (FragTrap &src)
{
	_name = src._name;
	_hitPts = src._hitPts;
	_energyPts = src._energyPts;
	_attackDmg = src._attackDmg;
	std::cout << "Copy assignment operator called\nFragTrap: [" << _name << "]\n";
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called\nFragTrap: [" << _name << "]\n";
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap [" << _name << "] high five \\(^_^)/\n";
}

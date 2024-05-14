/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:55:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:42:51 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Character.hpp"

Character::Character(void) : _name("UNAMED")
{
	unsigned int	i = 0;
	while (i < 4)
		_inventory[i++] = NULL;
	std::cout << "Character default constructor\n";
}

Character::Character(const std::string& name) : _name(name)
{
	unsigned int	i = 0;
	while (i < 4)
		_inventory[i++] = NULL;
	std::cout << "Character naming constructor\n";
}

Character::Character(const Character& other)
{
	*this = other;
	std::cout << "Character copy constructor\n";
}

Character::~Character(void)
{
	unsigned int	i = 0;
	while (i < 4 && _inventory[i] != NULL)
	{
		delete _inventory[i];
		_inventory[i++] = NULL;	
	}
	std::cout << "Character destructor\n";
}

Character& Character::operator= (const Character& other)
{
	if (this != &other)
	{
		_name.assign(other._name);
		unsigned int	i = 0;
		while (i < 4 && _inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i++] = NULL;
		}
		i = 0;
		while (i < 4 && other._inventory[i] != NULL)
		{
			_inventory[i] = other._inventory[i]->clone();
			i++;
		}
	}
	std::cout << "Character copy assignment operator\n";
	return (*this);
}

const std::string&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	unsigned int	i = 0;
	while (i < 4 && _inventory[i] != NULL)
		i++;
	if (i < 4 && _inventory[i] == NULL)
	{
		_inventory[i] = m;
		std::cout << _name << " equiped " << m->getType() << " in slot "
			<< i << "\n";
	}
	else
		std::cout << _name << "’s inventory is full\n";
}

AMateria*	Character::getMateriaAddress(int idx)
{
	if (idx < 4 && idx >= 0)
		return (_inventory[idx]);
	return (NULL);
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
	{
		std::cout << _name << " unequiped " << _inventory[idx]->getType()
			<< " in slot " << idx << "\n";
		_inventory[idx] = NULL;
		if (idx < 3)
		{
			unsigned int i = idx + 1;
			while (i < 4)
			{
				_inventory[idx] = _inventory[i];
				_inventory[i] = NULL;
				i++;
				idx++;
			}
		}
	}
	else
		std::cout << _name << "’s slot " << idx << " is empty\n";
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << _name << " can’t use object in slot " << idx << "\n";
}

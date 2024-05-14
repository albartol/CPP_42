/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:07:40 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:57:39 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	unsigned int	i = 0;
	while (i < 4)
		_source[i++] = NULL;
	std::cout << "MateriaSource default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
	std::cout << "MateriaSource copy constructor\n";
}

MateriaSource::~MateriaSource(void)
{
	unsigned int	i = 0;
	while (i < 4 && _source[i] != NULL)
	{
		delete _source[i];
		_source[i++] = NULL;
	}
	std::cout << "MateriaSource destructor\n";
}

MateriaSource& MateriaSource::operator= (const MateriaSource& other)
{
	if (this != &other)
	{
		unsigned int	i = 0;
		while (i < 4 && _source[i] != NULL)
		{
			delete _source[i];
			_source[i++] = NULL;
		}
		i = 0;
		while (i < 4 && other._source[i] != NULL)
		{
			_source[i] = other._source[i]->clone();
			i++;
		}
	}
	std::cout << "MateriaSource copy assignment operator\n";
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	unsigned int	i = 0;
	while (i < 4 && _source[i] != NULL)
		i++;
	if (i < 4 && _source[i] == NULL)
	{
		_source[i] = m;
		std::cout << "Stored " << m->getType() << " in slot " << i << "\n";
	}
	else
		std::cout << "MateriaSource is full\n";
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	unsigned int	i = 0;
	while (i < 4 && _source[i] != NULL)
	{
		if (_source[i]->getType() == type)
			return (_source[i]->clone());
		i++;
	}
	std::cout << "Materia not found\n";
	return (NULL);
}

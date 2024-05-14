/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:19:30 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:54:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("base type")
{
	std::cout << "AMateria default constructor\n";
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria type constructor\n";
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << "AMateria copy constructor\n";
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor\n";
}

AMateria& AMateria::operator= (const AMateria& other)
{
	(void)other;
	// if (this != &other)
	// 	_type.assign(other._type);
	std::cout << "AMateria copy assignment operator\n";
	return (*this);
}

const std::string&	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used on " << target.getName() << " *\n";
}

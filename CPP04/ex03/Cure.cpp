/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:35 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 17:00:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor\n";
}

Cure::Cure(const Cure& other) : AMateria("cure")
{
	(void)other;
	std::cout << "Cure copy constructor\n";
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor\n";
}

Cure& Cure::operator= (const Cure& other)
{
	(void)other;
	// if (this != &other)
	// 	_type.assign(other._type);
	std::cout << "Cure copy assignment operator\n";
	return (*this);
}

Cure*	Cure::clone() const
{
	Cure*	ptr = new Cure;
	if (ptr == NULL)
	{
		std::cerr << "Fail clonnig Cure\n";
		exit(1);
	}
	return (ptr);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

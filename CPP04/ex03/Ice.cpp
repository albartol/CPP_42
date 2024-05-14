/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:34 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:55:24 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor\n";
}

Ice::Ice(const Ice& other) : AMateria("ice")
{
	(void)other;
	std::cout << "Ice copy constructor\n";
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor\n";
}

Ice& Ice::operator= (const Ice& other)
{
	(void)other;
	// if (this != &other)
	// 	_type.assign(other._type);
	std::cout << "Ice copy assignment operator\n";
	return (*this);
}

Ice*	Ice::clone() const
{
	Ice*	ptr = new Ice;
	if (ptr == NULL)
	{
		std::cerr << "Fail clonnig Ice\n";
		exit(1);
	}
	return (ptr);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

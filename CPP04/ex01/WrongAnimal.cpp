/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:31:37 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:32:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator= (WrongAnimal& other)
{
	_type = other._type;
	std::cout << "WrongAnimal copy assignment operator called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sounds\n";
}

const std::string&	WrongAnimal::getType(void) const
{
	return (_type);
}

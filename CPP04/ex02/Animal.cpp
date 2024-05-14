/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:47:49 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 12:07:11 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(Animal& other) : _type(other._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator= (Animal& other)
{
	_type = other._type;
	std::cout << "Animal copy assignment operator called\n";
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

const std::string&	Animal::getType(void) const
{
	return (_type);
}

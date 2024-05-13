/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:15:55 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:18:07 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(Dog& other) : Animal()
{
	_type = other._type;
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator= (Dog& other)
{
	_type = other._type;
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Wooof!!\n";
}

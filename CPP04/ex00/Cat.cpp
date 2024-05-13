/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:10:44 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:15:28 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(Cat& other) : Animal()
{
	_type = other._type;
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator= (Cat& other)
{
	_type = other._type;
	std::cout << "Cat copy assignment operator called\n";
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeoow!!\n";
}

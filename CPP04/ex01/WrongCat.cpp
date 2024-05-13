/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:37:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:38:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal()
{
	_type = other._type;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator= (WrongCat& other)
{
	_type = other._type;
	std::cout << "WrongCat copy assignment operator called\n";
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sounds\n";
}

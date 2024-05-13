/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:15:55 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 18:46:28 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <new>
#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cerr << "Failed brain allocation in Dog\n";
		exit(1);
	}
	_brain->setIdea(0, "I am a dog");
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(Dog& other) : Animal()
{
	_type = other._type;
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cerr << "Failed brain allocation in Cat\n";
		exit(1);
	}
	*_brain = *other._brain;
	_brain->setIdea(0, "I am a dog");
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator= (Dog& other)
{
	_type = other._type;
	*_brain = *other._brain;
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Wooof!!\n"
		<< _brain->getIdea(0) << "\n";
}

void	Dog::setIdea(unsigned int i, std::string new_idea)
{
	_brain->setIdea(i, new_idea);
}
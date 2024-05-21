/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:10:44 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 17:12:43 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <new>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cerr << "Failed brain allocation in Cat\n";
		exit(1);
	}
	_brain->setIdea(0, "I am a cat");
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(Cat& other) : Animal()
{
	_type = other._type;
	_brain = new Brain();
	if (_brain == NULL)
	{
		std::cerr << "Failed brain allocation in Cat\n";
		exit(1);
	}
	*_brain = *other._brain;
	_brain->setIdea(0, "I am a cat");
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator= (Cat& other)
{
	_type = other._type;
	*_brain = *other._brain;
	std::cout << "Cat copy assignment operator called\n";
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeoow!!\n";
}

void	Cat::setIdea(unsigned int i, std::string new_idea)
{
	_brain->setIdea(i, new_idea);
}

void	Cat::printIdeas(void) const
{
	_brain->printIdeas();
}
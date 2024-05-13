/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:01:17 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 17:29:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator= (Brain& other)
{
	unsigned int	i = 0;
	if (this == &other)
		return (*this);
	while (i < 100)
	{
		ideas[i].assign(other.ideas[i]);
		i++;
	}
	std::cout << "Brain copy assignment operator called\n";
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}

void	Brain::setIdea(unsigned int i, std::string new_idea)
{
	if (i < 100)
		ideas[i].assign(new_idea);
}

const std::string	Brain::getIdea(unsigned int i) const
{
	if (i < 100)
		return (ideas[i]);
	return ("Undefined idea");
}

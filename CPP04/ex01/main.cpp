/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 18:17:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <new>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "Constructors\n\n";
	Animal* animal[6];
	std::cout << "\n";
	unsigned int	i = 0;
	while (i < 3)
	{
		animal[i] = new Dog();
		std::cout << "\n";
		if (animal[i++] == NULL)
		{
			std::cerr << "Failed Dog allocation in main\n";
			exit(1);
		}
	}
	std::cout << "\n";
	while (i < 6)
	{
		animal[i] = new Cat();
		std::cout << "\n";
		if (animal[i++] == NULL)
		{
			std::cerr << "Failed Cat allocation in main\n";
			exit(1);
		}
	}

	std::cout << "\nSounds\n\n";
	i = 0;
	while (i < 6)
		animal[i++]->makeSound();

	std::cout << "\nDestructors\n\n";
	i = 0;
	while (i < 6)
	{
		delete animal[i];
		std::cout << "\n";
		i++;
	}
	std::cout << "\nCopy test\n\n";
	Dog	a;
	Dog	b;
	Dog	c;

	a.setIdea(0, "I am a bird");
	a.makeSound();
	b.makeSound();
	c.makeSound();
	b = a;
	a = c;
	a.makeSound();
	b.makeSound();
	c.makeSound();
	return (0);
}

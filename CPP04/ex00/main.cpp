/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:39:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 12:00:38 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "Constructors\n\n";
	const Animal* animal = new Animal();
	std::cout << "\n";
	const Animal* dog = new Dog();
	std::cout << "\n";
	const Animal* cat = new Cat();
	std::cout << "\n";
	const WrongAnimal* wr_annimal = new WrongCat();
	std::cout << "\n";
	const WrongCat* wr_cat = new WrongCat();

	std::cout << "\nTypes\n\n";

	std::cout << animal->getType() << "\n"
		<< dog->getType() << "\n"
		<< cat->getType() << "\n"
		<< wr_annimal->getType() << "\n"
		<< wr_cat->getType() << "\n";

	std::cout << "\nSounds\n\n";

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wr_annimal->makeSound();
	wr_cat->makeSound();

	std::cout << "\nDestructors\n\n";

	delete animal;
	std::cout << "\n";
	delete dog;
	std::cout << "\n";
	delete cat;
	std::cout << "\n";
	delete wr_annimal;
	std::cout << "\n";
	delete wr_cat;
	return (0);
}

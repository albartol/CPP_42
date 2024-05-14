/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:38:51 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:53:36 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	std::cout << "Creating MateriaSource\n\n";
	MateriaSource* src = new MateriaSource();

	std::cout << "\nStoring Materias in source\n\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\nCreating Character\n\n";
	ICharacter* me = new Character("me");

	AMateria* tmp;

	std::cout << "\nCloning an Ice Materia from MateriaSource\n\n";
	tmp = src->createMateria("ice");

	std::cout << "\nEquipping Ice Materia clone to a Character\n\n";
	me->equip(tmp);

	std::cout << "\nCloning a Cure Materia from MateriaSource\n\n";
	tmp = src->createMateria("cure");

	std::cout << "\nEquipping Cure Materia clone to a Character\n\n";
	me->equip(tmp);

	std::cout << "\nCreating another Character\n\n";
	ICharacter* bob = new Character("bob");

	std::cout << "\nCharacter uses Materias on another\n\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\nDeleting MateriaSource and Characters\n\n";
	delete bob;
	delete me;
	delete src;
	return (0);
}

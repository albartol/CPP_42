/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 20:08:37 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	c1("n1");
	ClapTrap	c2(c1);
	ClapTrap	c3 = c2;
	ClapTrap	c4("n2");
	ScavTrap	s1("j1");
	ScavTrap	s2(s1);
	ScavTrap	s3 = s2;
	ScavTrap	s4("j2");
	FragTrap	f1("h1");
	FragTrap	f2(f1);
	FragTrap	f3 = f2;
	FragTrap	f4("h2");

	c4 = c3;
	s4 = s3;
	f4 = f3;
	c1.attack("enemy");
	c2.takeDamage(4);
	c3.beRepaired(9);
	c4.attack("enemy2");
	s1.attack("enemy3");
	s2.takeDamage(80);
	s3.beRepaired(90);
	s4.attack("enemy4");
	s4.guardGate();
	f1.attack("enemy5");
	f2.takeDamage(80);
	f3.beRepaired(90);
	f4.attack("enemy6");
	f4.highFivesGuys();
	return (0);
}
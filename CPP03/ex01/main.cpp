/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 19:17:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	c4 = c3;
	s4 = s3;
	c1.attack("enemy");
	c2.takeDamage(4);
	c3.beRepaired(9);
	c4.attack("enemy2");
	s1.attack("enemy3");
	s2.takeDamage(80);
	s3.beRepaired(90);
	s4.attack("enemy4");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 23:36:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	s1("j1");
	ScavTrap	s2(s1);
	ScavTrap	s3 = s2;
	ScavTrap	s4("j2");

	s4 = s3;
	s1.attack("enemy");
	s2.takeDamage(80);
	s3.beRepaired(90);
	s4.attack("enemy2");
	s4.guardGate();
	return (0);
}
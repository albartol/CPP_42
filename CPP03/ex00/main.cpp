/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 15:44:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	c1("n1");
	ClapTrap	c2(c1);
	ClapTrap	c3 = c2;
	ClapTrap	c4("n2");

	c4 = c3;
	c1.attack("enemy");
	c2.takeDamage(4);
	c3.beRepaired(9);
	c4.attack("enemy2");
	return (0);
}
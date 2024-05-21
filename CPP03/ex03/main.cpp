/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 14:09:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	d1("(o_o)");
	DiamondTrap	d2(d1);
	DiamondTrap	d3 = d2;
	DiamondTrap	d4;

	d4 = d3;

	d1.attack("enemy");
	d2.takeDamage(99);
	d2.takeDamage(100);
	d3.beRepaired(90);
	d4.guardGate();
	d4.highFivesGuys();
	d4.whoAmI();

	return (0);
}
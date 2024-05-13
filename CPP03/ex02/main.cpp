/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:12:32 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 23:36:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	f1("h1");
	FragTrap	f2(f1);
	FragTrap	f3 = f2;
	FragTrap	f4("h2");

	f4 = f3;
	f1.attack("enemy");
	f2.takeDamage(80);
	f3.beRepaired(90);
	f4.attack("enemy2");
	f4.highFivesGuys();
	return (0);
}
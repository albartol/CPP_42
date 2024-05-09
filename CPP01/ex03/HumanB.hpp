/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:32:01 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 03:27:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:

		std::string	name;
		Weapon	*weapon;

	public:

		HumanB(std::string new_name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon &new_weapon);

};

#endif

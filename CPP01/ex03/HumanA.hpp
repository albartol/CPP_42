/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:32:08 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 03:23:20 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	private:

		std::string	name;
		Weapon	&weapon;

	public:

		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA(void);
		void	attack(void) const;

};

#endif

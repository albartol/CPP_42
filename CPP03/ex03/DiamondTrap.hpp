/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:24:49 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 23:16:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;

	public:

		DiamondTrap(std::string name);
		DiamondTrap(void);
		DiamondTrap(DiamondTrap& copy);
		DiamondTrap& operator= (DiamondTrap& src);
		~DiamondTrap(void);
		void	whoAmI(void) const;
		using ScavTrap::attack;
};

#endif
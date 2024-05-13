/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:17:25 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 23:15:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(std::string name);
		ScavTrap(void);
		ScavTrap(ScavTrap& copy);
		ScavTrap& operator= (ScavTrap& src);
		~ScavTrap(void);
		void	attack(const std::string& target);
		void	guardGate(void) const;
};

#endif
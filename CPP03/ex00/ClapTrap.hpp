/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:13:58 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 16:39:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	private:

		std::string	_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;

	public:

		ClapTrap(std::string name);
		ClapTrap(void);
		ClapTrap(ClapTrap& copy);
		ClapTrap& operator= (ClapTrap& src);
		~ClapTrap(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
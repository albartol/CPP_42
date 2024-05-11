/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:01:02 by albartol          #+#    #+#             */
/*   Updated: 2024/05/11 20:03:22 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:

		FragTrap(std::string name);
		FragTrap(void);
		FragTrap(FragTrap& copy);
		FragTrap& operator= (FragTrap& src);
		~FragTrap(void);
		void	highFivesGuys(void) const;
};

#endif
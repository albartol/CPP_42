/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:05:27 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 00:10:07 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:

		std::string	type;

	public:

		Weapon(void);
		Weapon(std::string weapon_type);
		~Weapon(void);
		const std::string &	getType(void) const;
		void	setType(std::string	new_type);

};

#endif

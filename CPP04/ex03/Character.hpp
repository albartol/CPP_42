/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:56:05 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:35:29 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:

		std::string	_name;
		AMateria*	_inventory[4];

	public:

		Character(void);
		Character(const std::string& name);
		Character(const Character& other);

		~Character(void);

		Character& operator= (const Character& other);

		const std::string&	getName(void) const;

		void	equip(AMateria* m);
		AMateria*	getMateriaAddress(int idx);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif

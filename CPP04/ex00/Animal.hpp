/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:47:17 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:30:08 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	protected:

		std::string	_type;

	public:

		Animal(void);
		Animal(Animal& other);
		Animal& operator= (Animal& other);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		const std::string&	getType(void) const;
};

#endif

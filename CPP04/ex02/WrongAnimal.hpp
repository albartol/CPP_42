/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:31:49 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 11:36:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class	WrongAnimal
{
	protected:

		std::string	_type;

	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal& other);
		WrongAnimal& operator= (WrongAnimal& other);
		~WrongAnimal(void);
		void	makeSound(void) const;
		const std::string&	getType(void) const;
};

#endif

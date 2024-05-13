/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:10:42 by albartol          #+#    #+#             */
/*   Updated: 2024/05/13 17:16:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:

		Brain*	_brain;

	public:

		Cat(void);
		Cat(Cat& other);
		Cat& operator= (Cat& other);
		~Cat(void);
		void	makeSound(void) const;
};

#endif

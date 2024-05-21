/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:10:42 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 17:12:46 by albartol         ###   ########.fr       */
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
		void	setIdea(unsigned int i, std::string new_idea);
		void	printIdeas(void) const;

};

#endif

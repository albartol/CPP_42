/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:15:52 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 17:12:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{	
	private:

		Brain*	_brain;

	public:

		Dog(void);
		Dog(Dog& other);
		Dog& operator= (Dog& other);
		~Dog(void);
		void	makeSound(void) const;
		void	setIdea(unsigned int i, std::string new_idea);
		void	printIdeas(void) const;

};

#endif

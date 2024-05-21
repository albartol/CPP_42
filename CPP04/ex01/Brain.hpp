/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:01:21 by albartol          #+#    #+#             */
/*   Updated: 2024/05/21 17:06:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	private:

		std::string	ideas[100];

	public:

		Brain(void);
		Brain(Brain& other);
		Brain& operator= (Brain& other);
		~Brain(void);
		void	printIdeas(void) const;
		void	setIdea(unsigned int i, std::string new_idea);
		const std::string	getIdea(unsigned int i) const;
};

#endif

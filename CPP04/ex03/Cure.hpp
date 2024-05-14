/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:21:41 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 12:51:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:

		Cure(void);
		Cure(const Cure& other);

		~Cure(void);

		Cure& operator= (const Cure& other);

		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif

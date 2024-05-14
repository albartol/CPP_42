/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:10 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 16:35:34 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria*	_source[4];

	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource& other);

		~MateriaSource(void);

		MateriaSource& operator= (const MateriaSource& other);

		void	learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};

#endif


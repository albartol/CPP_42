/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:46:17 by albartol          #+#    #+#             */
/*   Updated: 2024/05/14 12:52:21 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:

		std::string	_type;

	public:

		AMateria(const std::string& type);
		AMateria(void);
		AMateria(const AMateria& other);

		virtual ~AMateria(void);

		AMateria& operator= (const AMateria& other);

		const std::string&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);
};

#endif

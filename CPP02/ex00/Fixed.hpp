/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:38:16 by albartol          #+#    #+#             */
/*   Updated: 2024/05/10 12:34:28 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <sys/types.h>

class	Fixed
{
	private:

		int	integer;
		static const int8_t	fract_bits;

	public:

		Fixed(void);
		Fixed(const Fixed & src);
		Fixed & operator= (const Fixed & src);
		~Fixed(void);
		int	getRawBits(void);
		void	setRawBits(int const raw);

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:38:16 by albartol          #+#    #+#             */
/*   Updated: 2024/05/12 00:16:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <sys/types.h>
# include <iostream>

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
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed(const int value);
		Fixed(const float value);
		float	toFloat(void) const;
		int	toInt(void) const;
		friend std::ostream & operator<< (std::ostream & os, const Fixed & src);
		bool operator< (const Fixed & other) const;
		bool operator> (const Fixed & other) const;
		bool operator>= (const Fixed & other) const;
		bool operator<= (const Fixed & other) const;
		bool operator== (const Fixed & other) const;
		bool operator!= (const Fixed & other) const;
		Fixed operator+ (const Fixed & other) const;
		Fixed operator- (const Fixed & other) const;
		Fixed operator* (const Fixed & other) const;
		Fixed operator/ (const Fixed & other) const;
		Fixed & operator++ (void);
		Fixed & operator++ (int);
		Fixed & operator-- (void);
		Fixed & operator-- (int);
		static const Fixed & max(const Fixed & src1, const Fixed & src2);
		static Fixed & max(Fixed & src1, Fixed & src2);
		static const Fixed & min(const Fixed & src1, const Fixed & src2);
		static Fixed & min(Fixed & src1, Fixed & src2);

};

#endif

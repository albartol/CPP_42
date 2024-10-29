/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:30:26 by albartol          #+#    #+#             */
/*   Updated: 2024/10/11 17:26:10 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stdint.h>

class Bureaucrat
{
	private:
		const std::string	_name;
		uint32_t	_grade;

		Bureaucrat(void);

	public:
		Bureaucrat(const std::string& name, uint32_t grade);
		Bureaucrat(const Bureaucrat& other);

		~Bureaucrat(void);

		Bureaucrat& operator= (const Bureaucrat& other);

		const std::string&	getName(void) const;
		uint32_t	getGrade(void) const;

		void	inrcrementGrade(void);
		void	decrementGrade(void);

		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too high";
			}
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too low";
			}
		};
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& src);

#endif
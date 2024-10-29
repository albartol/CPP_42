/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:22:50 by albartol          #+#    #+#             */
/*   Updated: 2024/10/14 19:26:07 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stdint.h>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		const uint32_t	_signGrade;
		const uint32_t	_execGrade;
		bool	_signed;

		AForm(void);

	public:
		AForm(const std::string& name, uint32_t signGrade, uint32_t execGrade);
		AForm(const AForm& other);

		virtual ~AForm(void);

		AForm& operator= (const AForm& other);

		const std::string&	getName(void) const;
		uint32_t	getSignGrade(void) const;
		uint32_t	getExecGrade(void) const;
		bool	getSigned(void) const;

		void	beSigned(const Bureaucrat& src);

		virtual void execute(const Bureaucrat& executor) = 0;

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

std::ostream& operator<< (std::ostream& os, const AForm& src);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:22:50 by albartol          #+#    #+#             */
/*   Updated: 2024/10/11 17:52:41 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stdint.h>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const uint32_t	_signGrade;
		const uint32_t	_execGrade;
		bool	_signed;

		Form(void);

	public:
		Form(const std::string& name, uint32_t signGrade, uint32_t execGrade);
		Form(const Form& other);

		~Form(void);

		Form& operator= (const Form& other);

		const std::string&	getName(void) const;
		uint32_t	getSignGrade(void) const;
		uint32_t	getExecGrade(void) const;
		bool	getSigned(void) const;

		void	beSigned(const Bureaucrat& src);

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

std::ostream& operator<< (std::ostream& os, const Form& src);

#endif
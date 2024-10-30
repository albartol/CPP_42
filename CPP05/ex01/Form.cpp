/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:22:59 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 12:40:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Form::Form(void) {}

Form::Form(const std::string& name, uint32_t signGrade, uint32_t execGrade) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name),
	_signGrade(other._signGrade), _execGrade(other._execGrade),
	_signed(other._signed) {}

Form::~Form(void) {}

Form& Form::operator= (const Form& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return *this;
}

const std::string& Form::getName(void) const
{
	return _name;
}

uint32_t Form::getSignGrade(void) const
{
	return _signGrade;
}

uint32_t Form::getExecGrade(void) const
{
	return _execGrade;
}

bool Form::getSigned(void) const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& os, const Form& src)
{
	os << "Name: " << src.getName() << "\nSign grade: "
		<< src.getSignGrade() << "\nExec grade: " << src.getExecGrade()
		<< "\nIs signed: " << src.getSigned() << "\n";
	return os;
}
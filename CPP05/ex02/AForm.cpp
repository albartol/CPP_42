/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:22:59 by albartol          #+#    #+#             */
/*   Updated: 2024/10/12 16:26:50 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// AForm::AForm(void) {}

AForm::AForm(const std::string& name, uint32_t signGrade, uint32_t execGrade) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name),
	_signGrade(other._signGrade), _execGrade(other._execGrade),
	_signed(false) {}

AForm::~AForm(void) {}

AForm& AForm::operator= (const AForm& other)
{
	if (this != &other)
		_signed = other.getSigned();
	return *this;
}

const std::string& AForm::getName(void) const
{
	return _name;
}

uint32_t AForm::getSignGrade(void) const
{
	return _signGrade;
}

uint32_t AForm::getExecGrade(void) const
{
	return _execGrade;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& os, const AForm& src)
{
	os << "Name: " << src.getName() << "\nSign grade: "
		<< src.getSignGrade() << "\nExec grade: " << src.getExecGrade()
		<< "\nIs signed: " << src.getSigned() << "\n";
	return os;
}
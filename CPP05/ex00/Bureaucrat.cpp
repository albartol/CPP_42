/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:29:27 by albartol          #+#    #+#             */
/*   Updated: 2024/10/10 20:33:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string& name, uint32_t grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name),
	_grade(other._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

const std::string& Bureaucrat::getName(void) const
{
	return _name;
}

uint32_t Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::inrcrementGrade(void)
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".\n";
	return os;
}
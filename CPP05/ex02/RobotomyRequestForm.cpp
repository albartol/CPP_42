/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:44:26 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 14:05:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		setSigned(other.getSigned());
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::cout << "<drilling noises>\n";
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << _target << "'s robotomy failed\n";
}
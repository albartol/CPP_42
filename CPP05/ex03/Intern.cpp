/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:48:40 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 16:01:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& other) {(void)other;}

Intern::~Intern(void) {}

Intern& Intern::operator= (const Intern& other) {(void)other;return *this;}

static AForm* create_shrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* create_robotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* create_presidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::searchForm(const std::string& name, const std::string& target) const
{
	std::string	form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	create_form	forms[] = {&create_shrubbery, &create_robotomy, &create_presidential};
	
	for (size_t i = 0; i < 3; i++) {
		if (name == form_names[i])
			return CALL_FN_PTR(forms[i], target);
	}
	throw UnknownFormException();
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	AForm	*new_form = NULL;
	try {
		new_form = searchForm(name, target);
	}
	catch (std::exception& ex) {
		std::cout << "Intern couldn’t create " << name << " form beause "
		<< ex.what() << ".\n";
	}
	if (new_form)
		std::cout << "Intern creates:\n" << *new_form;
	return new_form;
}

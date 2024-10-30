/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:44:26 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 13:29:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		setSigned(other.getSigned());
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string trees("\
	               ,@@@@@@@,\n\
	       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
	    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
	   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
	   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
	   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
	 `&%\\ ` /%&'    |.|        \\ '|8'\n\
	       |o|        | |         | |\n\
	       |.|        | |         | |\n\
	    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n");

	std::string	file_name(_target + "_shrubbery");
	std::ofstream	file(file_name.c_str());
	if (file.is_open())
	{
		file << trees;
		if (file.bad())
			std::cerr << "Writing error\n";
		else if (file.fail())
			std::cerr << "Logical error while writing\n";
	}
	else
		std::cerr << "Failed to open the file\n";
}
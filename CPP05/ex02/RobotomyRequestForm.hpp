/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:44:22 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 13:35:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	private:
        std::string _target;
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);

		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator= (const RobotomyRequestForm& other);

		void execute(const Bureaucrat& executor) const;
};

#endif
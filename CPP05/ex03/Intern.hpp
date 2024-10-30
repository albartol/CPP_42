/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:48:43 by albartol          #+#    #+#             */
/*   Updated: 2024/10/30 16:01:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>

class AForm;

#define CALL_FN_PTR(ptr_to_fn, target) (*(ptr_to_fn))(target)
typedef	AForm*	(*create_form)(const std::string& target);

class Intern
{
    private:
		AForm*	searchForm(const std::string& name, const std::string& target) const;

	public:
		Intern(void);
		Intern(const Intern& other);

		~Intern(void);

		Intern& operator= (const Intern& other);

		AForm*	makeForm(const std::string& name, const std::string& target) const;

        class UnknownFormException: public std::exception
        {
            virtual const char* what() const throw() {return "Form doesn't exist";}
        };
};

#endif
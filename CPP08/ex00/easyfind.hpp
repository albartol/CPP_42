/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:57:49 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 17:36:55 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception {
	virtual const char* what() const throw() {
		return "Value not in container";
	}
};

template <class T> int easyfind(T &cont, int val) {
	
	for (size_t i = 0; i < cont.size(); i++) {
		if ()
			return 
	}
	throw NotFoundException();
}

#endif
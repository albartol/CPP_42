/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:57:49 by albartol          #+#    #+#             */
/*   Updated: 2024/11/02 14:48:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception {
	virtual const char* what() const throw() {
		return "Value not in container";
	}
};

template <class T> void easyfind(T &cont, int val) {
	if (std::find(cont.begin(), cont.end(), val) != cont.end())
		return ;
	throw NotFoundException();
}

#endif
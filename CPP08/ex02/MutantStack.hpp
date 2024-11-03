/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:17:19 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 03:19:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &other) {
			*this = other;
		};
		~MutantStack(void) {};
		MutantStack& operator=(const MutantStack &other) {
			std::stack<T, Container>::operator=(other);
			return *this;
		};
	typedef typename Container::iterator iterator;
	iterator begin() {
		return this->c.begin();
	};
	iterator end() {
		return this->c.end();
	};
};
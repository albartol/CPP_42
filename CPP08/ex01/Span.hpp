/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:34:16 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 03:50:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>

class Span
{
	private:
		unsigned int	_max_elements;
		std::vector<int>	_elements;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		~Span(void);
		Span& operator=(const Span &other);

		void addNumber(int num);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void addNumber(std::list<int>::iterator start, std::list<int>::iterator end);
		void addNumber(std::deque<int>::iterator start, std::deque<int>::iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		const std::vector<int>& getElements(void) const;

		class MaxElementsException: public std::exception {
			virtual const char* what() const throw() {
				return "Trying to store elements over the limit";
			}
		};
		class InvalidSpanException: public std::exception {
			virtual const char* what() const throw() {
				return "Span can't be found";
			}
		};
};

std::ostream& operator<<(std::ostream &os, const Span &src);
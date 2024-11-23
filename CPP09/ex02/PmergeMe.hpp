/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:39:47 by albartol          #+#    #+#             */
/*   Updated: 2024/11/23 18:37:39 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RED "\033[0;91m"
# define RESET "\033[0m"

# include <exception>
# include <algorithm>
# include <iostream>
# include <climits>
# include <iterator>
# include <time.h>
# include <string>
# include <vector>
# include <list>

template <class T>
typename T::iterator binary_search(int num,
	typename T::iterator first, typename T::iterator last) {

	typename T::iterator	pos;
	while (std::distance(first, last) > 1) {
		pos = first;
		std::advance(pos, std::distance(first, last) / 2);
		if (num > *pos)
			first = pos;
		else if (num < *pos)
			last = pos;
		else
			return pos;
	}
	if (num > *first) {
		std::advance(first, 1);
		return first;
	}
	return first;
}


class PmergeMe
{
	private:
		std::vector<int>	_first_data;
		std::list<int>	_second_data;
		bool	parseInput(std::string &);
		clock_t	sortFirst(void);
		clock_t	sortSecond(void);
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		~PmergeMe(void);
		PmergeMe & operator=(const PmergeMe &);
		void	startPmergeMe(std::string input);
		static int	error(const char *);
		class InvalidInput: public std::exception {
			virtual const char *what() const throw() {
				return "Invalid input";
			}
		};
};

#endif
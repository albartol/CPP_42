/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:39:47 by albartol          #+#    #+#             */
/*   Updated: 2024/11/12 17:47:27 by albartol         ###   ########.fr       */
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
# include <time.h>
// # include <sstream>
# include <string>
# include <vector>
# include <list>
// # include <deque>

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:15:04 by albartol          #+#    #+#             */
/*   Updated: 2024/11/09 22:52:57 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# define RED "\033[0;91m"
# define RESET "\033[0m"

# include <exception>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <string>
# include <stack>

#define CALL_FN_PTR(ptr_to_fn, num1, num2) (this->*(ptr_to_fn))(num1, num2)

class RPN
{
	private:
		std::string	_data;
		typedef int	(RPN::*operation)(int,int);
		int	add(int, int);
		int	sub(int, int);
		int	mul(int, int);
		int	div(int, int);
		bool	parseInput(std::string &);
	public:
		RPN(void);
		RPN(const RPN &);
		~RPN(void);
		RPN & operator=(const RPN &);
		void	startRPN(std::string input);
		static int	error(const char *);
		class DivideByZero: public std::exception {
			virtual const char *what() const throw() {
				return "Division by zero";
			}
		};
		class InvalidInput: public std::exception {
			virtual const char *what() const throw() {
				return "Invalid input";
			}
		};
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:14:57 by albartol          #+#    #+#             */
/*   Updated: 2024/11/09 23:04:55 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other): _data(other._data) {}

RPN::~RPN(void) {}

RPN & RPN::operator=(const RPN &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

int	RPN::error(const char *message) {
	std::cerr << RED"Error: " << message << RESET"\n";
	return 1;
}

bool	RPN::parseInput(std::string &input) {
	size_t pos = input.find_first_not_of(' ');
	if (pos == std::string::npos)
		return false;
	std::string	valid("0123456789-+*/");
	unsigned char c;
	long	num_elements = 0;
	while (pos != std::string::npos) {
		if (pos + 1 < input.size() && input[pos + 1] != ' ')
			return false;
		c = input[pos];
		if (std::find(valid.begin(), valid.end(), c) == valid.end())
			return false;
		_data.append(1, c);
		num_elements++;
		if (pos + 1 == input.size())
			break;
		pos = input.find_first_not_of(' ', pos + 1);
	}
	if (num_elements == 2 || !std::isdigit(_data[0]) || (num_elements > 2
		&& (!std::isdigit(_data[1]) || std::isdigit(_data[_data.size() - 1]))))
		return false;
	long	num_operators = std::count(_data.begin(), _data.end(), '-');
	num_operators += std::count(_data.begin(), _data.end(), '+');
	num_operators += std::count(_data.begin(), _data.end(), '*');
	num_operators += std::count(_data.begin(), _data.end(), '/');
	long	num_operands = num_elements - num_operators;
	if (num_operands == num_operators + 1)
		return true;
	return false;
}

void	RPN::startRPN(std::string input) {
	if (input.empty() || !parseInput(input))
		throw InvalidInput();
	std::stack<int>	temp;
	operation operations[] = {&RPN::add, &RPN::sub, &RPN::mul, &RPN::div};
	std::string	operators("+-*/");
	std::ostringstream	buff;
	for (size_t i = 0; i < _data.size(); i++) {
		if (std::isdigit(_data[i]))
			temp.push(_data[i] - '0');
		else {
			if (temp.size() < 2)
				throw InvalidInput();
			int	num2 = temp.top();
			temp.pop();
			int	num1 = temp.top();
			temp.pop();
			temp.push(CALL_FN_PTR(operations[operators.find(_data[i])], num1, num2));
			buff << "operation: " << num1 << " " << _data[i] << " "
				<< num2 << " = " << temp.top() << "\n";
			// std::cout << "operation: " << num1 << " " << _data[i] << " "
			// 	<< num2 << " = " << temp.top() << "\n";
		}
	}
	if (temp.size() > 1)
		throw InvalidInput();
	std::cout << buff.str() << "Result: " << temp.top() << std::endl;
	// std::cout << "Result: " << temp.top() << std::endl;
}

int	RPN::add(int num1, int num2) {
	return num1 + num2;
}
int	RPN::sub(int num1, int num2) {
	return num1 - num2;
}
int	RPN::mul(int num1, int num2) {
	return num1 * num2;
}
int	RPN::div(int num1, int num2) {
	if (num2 == 0)
		throw DivideByZero();
	return num1 / num2;
}

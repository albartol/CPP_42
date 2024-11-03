/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 02:16:12 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 03:26:52 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "-----------MutantStack test-----------\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Last element: " << mstack.top() << "\n";

		mstack.pop();

		std::cout << "Stack size: " << mstack.size() << "\n";

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(77);
		mstack.push(73);
		mstack.push(37);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << "\n";
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "-----------List test-----------\n";
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "Last element: " << mstack.back() << "\n";

		mstack.pop_back();

		std::cout << "List size: " << mstack.size() << "\n";

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(77);
		mstack.push_back(73);
		mstack.push_back(37);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << "\n";
			++it;
		}
	}
	return 0;
}
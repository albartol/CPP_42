/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:46:37 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 14:27:13 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

Base* generate(void)
{
	std::srand(time(NULL));
	int val = std::rand() % 3;
	if (!val)
		return new A();
	if (val == 1)
		return new B();
	return new C();
}

void identify(Base* p)
{
	char type = '~';
	if (dynamic_cast<A*>(p))
		type = 'A';
	else if (dynamic_cast<B*>(p))
		type = 'B';
	else if (dynamic_cast<C*>(p))
		type = 'C';
	std::cout << "Object [Base* p] type is: '" << type << "'\n";
}

void identify(Base& p)
{
	char type = '~';
	A a_ref;
	B b_ref;
	C c_ref;
	try
	{
		a_ref = dynamic_cast<A&>(p);
		type = 'A';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		try
		{
			b_ref = dynamic_cast<B&>(p);
			type = 'B';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			try
			{
				c_ref = dynamic_cast<C&>(p);
				type = 'C';
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	std::cout << "Object [Base& p] type is: '" << type << "'\n";
}

int	main(void)
{
	Base	*random_class;

	random_class = generate();
	if (!random_class)
		return 1;

	std::cout << "Identify with ptr:" << "\n";
	identify(random_class);

	std::cout << "Identify with ref:" << "\n";
	identify(*random_class);

	delete random_class;
	return 0;
}

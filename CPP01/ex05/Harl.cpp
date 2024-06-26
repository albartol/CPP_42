/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:53:04 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 19:09:17 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sys/types.h>
#include <iostream>
#include "Harl.hpp"

// Harl::Harl(void) : levels{DEBUG, INFO, WARNING, ERROR},
// actions{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}
// {}

Harl::Harl(void)
{
	levels[0] = DEBUG;
	levels[1] = INFO;
	levels[2] = WARNING;
	levels[3] = ERROR;

	actions[0] = &Harl::debug;
	actions[1] = &Harl::info;
	actions[2] = &Harl::warning;
	actions[3] = &Harl::error;
}

Harl::~Harl(void) {}

void	Harl::complain(std::string level) const
{
	u_int32_t	i;

	i = 0;
	while (i < LEVELS_NUM && level.compare(levels[i]))
		i++;
	if (i < LEVELS_NUM)
		CALL_MEMBER_FN(actions[i])();
}

void	Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!\n";
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here since "
		<< "last month.\n";
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

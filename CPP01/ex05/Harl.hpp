/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:47:35 by albartol          #+#    #+#             */
/*   Updated: 2024/05/09 18:55:46 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define CALL_MEMBER_FN(ptr_to_fn) (this->*(ptr_to_fn))
# define DEBUG "DEBUG"
# define INFO "INFO"
# define WARNING "WARNING"
# define ERROR "ERROR"
# define LEVELS_NUM 4

class	Harl;

typedef	void	(Harl::*fn_level)(void) const;

class	Harl
{
	private:

		std::string	levels[LEVELS_NUM];
		fn_level	actions[LEVELS_NUM];
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;

	public:

		Harl(void);
		~Harl(void);
		void	complain(std::string level) const;

};

#endif

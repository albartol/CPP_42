/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:23:12 by albartol          #+#    #+#             */
/*   Updated: 2024/05/08 20:06:25 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:

		std::string	name;

	public:

		void	announce(void);
		void	set_name(std::string new_name);
		Zombie(std::string new_name);
		Zombie(void);
		~Zombie(void);

};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:08:34 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 15:31:31 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

template <class arg> void iter(arg *array, size_t len, void (*fn)(arg &a))
{
	for (size_t i = 0; i < len; i++)
	{
		fn(array[i]);
	}
};

#endif
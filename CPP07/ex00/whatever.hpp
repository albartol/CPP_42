/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:49:40 by albartol          #+#    #+#             */
/*   Updated: 2024/10/31 15:08:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <class arg> void swap(arg& a, arg& b)
{
    arg temp = a;
    a = b;
    b = temp;
};

template <class arg> arg min(arg a, arg b)
{
    return a < b ? a : b;
};

template <class arg> arg max(arg a, arg b)
{
    return a > b ? a : b;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:37:29 by albartol          #+#    #+#             */
/*   Updated: 2024/11/03 02:42:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <class T> class Array
{
	private:
		T	*_element;
		unsigned int	_size;
	public:
		Array(void): _size(1) {
			_element = new T[_size];
		};
		Array(unsigned int n): _size(n) {
			_element = new T[_size];
		};
		Array(const Array &other): _element(NULL) {
			*this = other;
		};
		~Array(void) {
			delete[] _element;
		};
		Array& operator= (const Array &other) {
			if(this != &other){
				if (_element)
					delete[] _element;
				_size = other._size;
				_element = new T[_size];
				for (size_t i = 0; i < _size; i++) {
					_element[i] = other._element[i];
				}
			}
			return *this;
		};
		T& operator[] (unsigned int i) {
			if(i >= _size){
				throw OutOfBoundsExecption();
			}
			return _element[i];
		};
		unsigned int size(void) const {
			return _size;
		};
		class OutOfBoundsExecption: public std::exception {
			virtual const char* what() const throw() {
				return "Index out of bounds";
			}
		};
};

#endif
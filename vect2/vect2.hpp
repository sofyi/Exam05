/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:42:03 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/23 18:48:43 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class vect2
{
	private:
		int data[2];
	public:
		vect2();
		vect2 (int , int);
		~vect2();
		vect2(vect2 &obj);
		vect2 & operator=(const vect2 &obj);
		int operator[](int index) const;
		int& operator[](int index);
		vect2 operator++();
		vect2 operator++(int);// hay heya el haaaj tetlkbaat i++ postfix
		vect2 operator--();
		vect2 operator--(int);
		vect2& operator+=(const vect2 &obj);
		vect2& operator-=(const vect2 &obj);
		vect2 operator*(int)const;
		vect2 operator+(const vect2& obj)const;
		vect2 operator-(const vect2& obj)const;
		vect2 operator-()const;
		vect2& operator*=(int);
		bool operator==(const vect2 & obj)const;
		bool operator!=(const vect2 & obj)const;
		
};

std::ostream& operator<<(std::ostream &os, const vect2& obj);
vect2 operator*(int val, const vect2 &obj);
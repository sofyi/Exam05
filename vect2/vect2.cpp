/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:54:01 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/23 18:48:59 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::~vect2(){}

vect2::vect2()
{
	data[0] = 0;
	data[1] = 0;
}

vect2::vect2 (int n1 , int n2)
{
	data[0] = n1;
	data[1] = n2;
}

vect2::vect2(vect2 &obj)
{
	*this = obj;
}

vect2& vect2::operator=(const vect2 &obj)
{
	data[0] = obj.data[0];
	data[1] = obj.data[1];
	return *this;
}

int vect2::operator[](int index) const
{
	return data[index];
}

int& vect2::operator[](int index)
{
	return data[index];
}
std::ostream& operator<<(std::ostream &os, const vect2& obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return os;
}

vect2 vect2::operator++()
{
	data[0]++;
	data[1]++;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tm;
	tm.data[0] = data[0];
	tm.data[1] = data[1];
	
	data[0]++;
	data[1]++;
	return tm;
}

vect2 vect2::operator--()
{
	data[0]--;
	data[1]--;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 tm;
	tm.data[0] = data[0];
	tm.data[1] = data[1];
	
	data[0]--;
	data[1]--;
	return tm;
}
vect2& vect2::operator+=(const vect2& obj)
{
	data[0] = data[0] + obj.data[0];	
	data[1] = data[1] + obj.data[1];
	return *this;
}

vect2& vect2::operator-=(const vect2& obj)
{
	data[0] = data[0] - obj.data[0];	
	data[1] = data[1] - obj.data[1];
	return *this;	
}
vect2 vect2::operator*(int val)const
{
	vect2 obj;
	obj.data[0] = data[0] * val;
	obj.data[1] = data[1] * val;
	return obj;
}

vect2 vect2::operator+(const vect2& obj)const
{
	vect2 ret;
	
	ret.data[0] = data[0] + obj.data[0];
	ret.data[1] = data[1] + obj.data[1];
	return ret;
}

vect2 vect2::operator-(const vect2& obj)const
{
	vect2 ret;
	
	ret = *this;
	ret -= obj;
	return ret;
}

vect2 vect2::operator-()const
{
	vect2 ret;

	ret.data[0] =  data[0] * (-1);
	ret.data[1] =  data[1] * (-1);
	return ret;
}

vect2 operator*(int val, const vect2 &obj)
{
	vect2 ret;

	ret = obj * val;
	return ret;
}

vect2& vect2::operator*=(int a)
{
	data[0] = data[0] * a;
	data[1] = data[1] * a;
	return *this;
}

bool vect2::operator==(const vect2 & obj)const
{
	if (obj.data[0] == data[0] && obj.data[1] == data[1])
		return true;
	return false;
}
bool vect2::operator!=(const vect2 & obj)const
{
	if (!(obj == *this))
		return true;
	return false;
}


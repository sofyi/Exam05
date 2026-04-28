/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:57:13 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/25 15:57:02 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <algorithm>

//-----------------------OrthoDox----------------

bigint::~bigint(){}

bigint::bigint()
{
	Bigintv.push_back(0);
}

bigint::bigint(unsigned int val)
{
	if (val == 0)
		Bigintv.push_back(0);
	while (val != 0)
	{
		Bigintv.push_back(val % 10);
		val /= 10;
	}
}

bigint::bigint(const bigint & obj)
{
	Bigintv = obj.Bigintv;	
}

bigint& bigint::operator=(const bigint & obj)
{
	if (&obj != this)
		Bigintv = obj.Bigintv;
	return *this;
}

//---------------------MemberFunction

unsigned int bigint::BigintToint()const
{
	long res;
	
	res = 0;
	for(int i = 0; i < Bigintv.size(); i++)
	{
		res = res * 10 + Bigintv[i];
		if (res > std::numeric_limits<unsigned int>::max())
			return  std::numeric_limits<unsigned int>::max();
	}
	return res;
}
std::vector<unsigned int> bigint::get_v()const
{
	return Bigintv;
}
bigint bigint::operator+(const bigint& obj) const
{
	bigint ret;
	size_t tak;
	size_t max;
	size_t n1 , n2;
	size_t  res;
	
	ret.Bigintv.pop_back();
	tak = 0;
	max = std::max(obj.Bigintv.size(), Bigintv.size());
	for (int index = 0; index < max; index++)
	{
		if ((obj.Bigintv.size()) > index)
			n1 = obj.Bigintv[index];
		else
			n1 = 0;
		if ((Bigintv.size()) > index)
			n2 = Bigintv[index];
		else
			n2 = 0;
		res = n1 + n2 + tak;
		ret.Bigintv.push_back(res % 10);
		tak = res / 10;
	}
	if (tak > 0)
		ret.Bigintv.push_back(tak);
	return ret;
}

std::ostream& operator<<(std::ostream& p, const bigint& obj)
{
	std::vector<unsigned int> v;

	v = obj.get_v();
	for(int i = v.size() - 1; i >= 0; i--)
		p << v[i];
	return p;
}

bigint& bigint::operator+=(const bigint& obj)
{
	*this = *this + obj;
	return *this;
}
bigint& bigint::operator++()
{
  //++i
  	*this = *this + 1;
	return *this;
}
bigint bigint::operator++(int)
{
	//i++
	bigint tmp;

	tmp = *this;
	++(*this);
	return tmp;
}

bigint bigint::operator>>(unsigned int shift)
{
	bigint ret;

	ret = *this;
	while (shift > 0)
	{
		ret.Bigintv.erase(ret.Bigintv.begin());
		shift--;	
	}
	return ret;
}

bigint bigint::operator<<(unsigned int shift)
{
	bigint ret;

	ret = *this;
	while (shift > 0)
	{
		ret.Bigintv.insert(ret.Bigintv.begin(), 0);
		shift--;
	}
	return ret;	
}

bigint& bigint::operator>>=(const bigint &val)
{
	*this = *this >> val.BigintToint();
	return *this;
}
bigint& bigint::operator<<=(const bigint &val)
{

	*this = *this << val.BigintToint();
	return *this;
}
bool bigint::operator<(const bigint& obj)const
{
	int i = 0;
	while (i < obj.Bigintv.size() && i < Bigintv.size())
	{
		if (Bigintv[i] == obj.Bigintv[i])
			i++;
	}
	if ( i < Bigintv.size() && i < obj.Bigintv.size() && Bigintv[i] < obj.Bigintv[i])
		return true; 
	return false;
}

bool bigint::operator>(const bigint& obj)const
{
	int i = 0;
	while (i < obj.Bigintv.size() && i < Bigintv.size())
	{
		if (Bigintv[i] == obj.Bigintv[i])
			i++;
	}
	if ( (i < Bigintv.size() && i < obj.Bigintv.size() && Bigintv[i] > obj.Bigintv[i]) || Bigintv.size() > i)
		return true; 
	return false;
}
bool bigint::operator==(const bigint& obj)const
{
	int i = 0;
	while (i < obj.Bigintv.size() && i < Bigintv.size())
	{
		if (Bigintv[i] == obj.Bigintv[i])
			i++;
	}
	if ( i == Bigintv.size() && obj.Bigintv.size())
		return true; 
	return false;
}
bool bigint::operator!=(const bigint& obj)const
{
	if ((*this == obj))
		return false;
	return true;
}
bool bigint::operator<=(const bigint& obj)const
{
	if ((*this == obj) || (*this < obj))
		return true;
	return false;
}	
bool bigint::operator>=(const bigint& obj)const
{
	if ((*this == obj) || (*this > obj))
			return true;
	return false;
}
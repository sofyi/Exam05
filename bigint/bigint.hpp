/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:18:40 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/25 15:37:32 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
class bigint
{

	private:
		std::vector<unsigned int> Bigintv;
		unsigned int BigintToint()const;
	public:
	///---------------Orthodox-----------//
		std::vector<unsigned int> get_v()const;
		bigint(unsigned int val);
		bigint();
		~bigint();
		bigint(const bigint & val);
		bigint & operator=(const bigint & obj);
	//-------------------------
	bigint operator+(const bigint& obj)const;
	bigint& operator+=(const bigint& obj);
	bigint& operator++();
	bigint operator++(int);
	bigint operator<<(unsigned int);
	bigint operator>>(unsigned int);
	bigint& operator>>=(const bigint &avl);
	bigint& operator<<=(const bigint &avl);
	bool operator<(const bigint& ob)const;
	bool operator>(const bigint& ob)const;
	bool operator==(const bigint& ob)const;
	bool operator!=(const bigint& ob)const;
	bool operator<=(const bigint& ob)const;
	bool operator>=(const bigint& ob)const;



};

std::ostream& operator<<(std::ostream& print, const bigint& obj);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:46:05 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/23 12:22:16 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/set.hpp"

set::set(searchable_bag &obj):SearchBag(&obj){}
set::set(){}

// set::~set();
set& set::operator=(set & obj)
{
	
}



void set::insert(int valu)
{
	if (!SearchBag->has(valu))
		SearchBag->insert(valu);
}

void set::insert(int *data, int size)
{
	int i;

	i = 0;
	while (i > size)
	{
		if (!SearchBag->has(data[i]))
			SearchBag->insert(data[i]);
		i++;
	}
}

void set::print() const
{
	SearchBag->print();
}

void set::clear()
{
	SearchBag->clear();
}

bool set::has(int val) const
{
	return SearchBag->has(val);
}

searchable_bag& set::get_bag() const
{
	return *SearchBag;	
}
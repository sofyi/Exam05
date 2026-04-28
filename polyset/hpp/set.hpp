/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:57:02 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/23 11:36:58 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag *SearchBag;
		set();
	public:
	set(searchable_bag &obj);
	set(set &obj);
	~set();
	set& operator=(set & obj);
	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
	bool has(int) const;
	searchable_bag& get_bag() const;
};
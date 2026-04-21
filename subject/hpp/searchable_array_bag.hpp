/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:12:45 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/21 13:09:48 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once


#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		bool has(int) const;
};
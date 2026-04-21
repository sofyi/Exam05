/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:04:45 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/21 13:12:02 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/searchable_array_bag.hpp"

bool searchable_array_bag::has(int find) const
{
	for(int i = 0;i < size ; i++)
		if (data[i] == find)
			return true;
	return false;
}
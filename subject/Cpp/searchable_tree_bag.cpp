/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:26:31 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/21 16:29:19 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int find) const
{
	node *s;

	s = tree;
	while (s)
	{
		if (find == s->value)
			return true;
		if (find > s->value)
			s = s
	}
	return false;
}
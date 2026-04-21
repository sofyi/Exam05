/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:20:38 by slamhaou          #+#    #+#             */
/*   Updated: 2026/04/21 13:26:26 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "searchable_bag.hpp"
#include  "tree_bag.hpp"
class searchable_tree_bag: public tree_bag , public searchable_bag
{
	public:
		bool has(int) const;
};
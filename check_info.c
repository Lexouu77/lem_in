/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:19:54 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 15:34:52 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void		set_weight(t_colony *colony, t_room *node, int n)
{
	int	i;

	i = 0;
	while (i < node->number_of_link)
	{
		if ((node->next[i]->weight == -1 || node->next[i]->weight > n)
				&& n < colony->number_of_rooms)
		{
			node->next[i]->weight = n;
			set_weight(colony, node->next[i], n + 1);
		}
		++i;
	}
}

int					check_info(t_colony *colony)
{
	if (!colony->end->number_of_link)
		return (1);
	colony->end->weight = 0;
	set_weight(colony, colony->end, 1);
	if (colony->start->weight < 0)
		return (1);
	return (0);
}

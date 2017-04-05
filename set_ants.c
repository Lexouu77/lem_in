/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:29:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 18:15:31 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_ants(t_colony *colony)
{
	int	i;

	i = -1;
	if (!(colony->ants = (t_ant **)malloc(sizeof(t_ant *) *
					colony->number_of_ants)))
		ft_malloc_error();
	while (++i < colony->number_of_ants)
	{
		if (!(colony->ants[i] = (t_ant *)malloc(sizeof(t_ant))))
			ft_malloc_error();
		colony->ants[i]->number = i + 1;
		colony->ants[i]->is_at_end = 0;
		colony->ants[i]->path_to_take = colony->path;
		colony->ants[i]->actual_room = colony->path[0];
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 00:54:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/23 13:08:45 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				convert_info(t_colony *colony)
{
	int	i;

	i = -1;
	if (!(colony->room_names = (t_room **)malloc(sizeof(t_room*) *
					colony->number_of_rooms + 1)))
		ft_malloc_error();
	while (++i < colony->number_of_rooms)
	{
		if (!(colony->room_names[i] = (t_room *)malloc(sizeof(t_room))))
			ft_malloc_error();
		colony->room_names[i]->is_full = 0;
		colony->room_names[i]->number_of_link = 0;
		colony->room_names[i]->ant = NULL;
		colony->room_names[i]->is_end = 0;
		colony->room_names[i]->is_start = 0;
		colony->room_names[i]->next = NULL;
		colony->room_names[i]->weight = -1;
		colony->room_names[i]->is_used = 0;
		colony->room_names[i]->room_name = ft_strdup(colony->rooms[i]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:25:38 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 14:36:20 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_room		*get_next_room(t_room *node)
{
	t_room		*tmp;
	int			i;

	i = 0;
	tmp = node->next[0];
	while (++i < node->number_of_link)
		if (node->next[i]->weight < tmp->weight && node->next[i]->weight >= 0)
			tmp = node->next[i];
	return (tmp);
}

void				get_paths(t_colony *colony)
{
	int		i;
	t_room	*tmp;

	tmp = colony->start;
	i = -1;
	if (!(colony->path = (char **)malloc(sizeof(char *) *
						colony->start->weight + 2)))
		ft_malloc_error();
	while (++i < colony->start->weight + 1 && !tmp->is_end)
	{
		colony->path[i] = ft_strdup(tmp->room_name);
		tmp = get_next_room(tmp);
	}
	colony->path[i] = ft_strdup(tmp->room_name);
	colony->number_of_paths = i + 1;
}

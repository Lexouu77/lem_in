/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:10:41 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/26 15:17:24 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	set_old_place(t_colony *colony, int n)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++k < colony->number_of_rooms)
		if (!ft_strcmp(colony->ants[n]->actual_room,
					colony->room_names[k]->room_name))
			break ;
	colony->room_names[k]->is_full = 0;
	colony->room_names[k]->ant = NULL;
}

static	void	set_new_place(t_colony *colony, int n)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < colony->number_of_paths)
		if (!ft_strcmp(colony->ants[n]->actual_room,
					colony->ants[n]->path_to_take[i]))
			break ;
	while (++k < colony->number_of_rooms)
		if (!ft_strcmp(colony->ants[n]->path_to_take[i + 1],
					colony->room_names[k]->room_name))
			break ;
	if (colony->room_names[k]->is_end)
	{
		colony->ants[n]->is_at_end = 1;
		++colony->number_of_ants_in_end;
		colony->ants[n]->actual_room = colony->end->room_name;
	}
	else
	{
		colony->room_names[k]->is_full = 1;
		colony->room_names[k]->ant = colony->ants[n];
		colony->ants[n]->actual_room = colony->room_names[k]->room_name;
	}
}

static	void	move(t_colony *colony, int n)
{
	if (ft_strcmp(colony->ants[n]->actual_room, colony->start->room_name))
		set_old_place(colony, n);
	set_new_place(colony, n);
	if (!colony->hide_ants_moves)
	{
		if (colony->color)
			ft_printf("L%[[FG_YEL,SP_RST]d-%[[FG_MAG,SP_RST]s ", n + 1,
					colony->ants[n]->actual_room);
		else
			ft_printf("L%d-%s ", n + 1, colony->ants[n]->actual_room);
	}
}

static	int		move_is_possible(t_colony *colony, int n)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < colony->number_of_paths)
		if (!ft_strcmp(colony->ants[n]->actual_room,
					colony->ants[n]->path_to_take[i]))
			break ;
	while (++k < colony->number_of_rooms)
		if (!ft_strcmp(colony->ants[n]->path_to_take[i + 1],
					colony->room_names[k]->room_name))
			break ;
	if (colony->room_names[k]->is_full)
		return (0);
	return (1);
}

void			move_ants(t_colony *colony)
{
	int		i;

	i = -1;
	while (++i < colony->number_of_ants)
	{
		if (colony->ants[i]->is_at_end)
			continue ;
		if (!move_is_possible(colony, i))
			break ;
		move(colony, i);
		++colony->moves;
	}
}

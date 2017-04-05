/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 03:23:45 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 17:47:32 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		check_link(t_colony *colony, char *src, char *to_add)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < colony->number_of_rooms)
		if (!ft_strcmp(colony->room_names[i]->room_name, src))
			break ;
	while (++k < colony->room_names[i]->number_of_link)
		if (!ft_strcmp(colony->room_names[i]->next[k]->room_name, to_add))
			return (1);
	return (0);
}

static	void	relink_it(t_colony *colony, char *src, char *to_add)
{
	t_room		**cpy;
	int			i;
	int			k;
	int			j;

	if (check_link(colony, src, to_add))
		return ;
	i = -1;
	while (++i < colony->number_of_rooms)
		if (!ft_strcmp(colony->room_names[i]->room_name, src))
			break ;
	cpy = colony->room_names[i]->next;
	if (!(colony->room_names[i]->next = (t_room **)malloc(sizeof(t_room *) *
					(colony->room_names[i]->number_of_link + 1))))
		ft_malloc_error();
	k = -1;
	while (++k < colony->room_names[i]->number_of_link)
		colony->room_names[i]->next[k] = cpy[k];
	j = -1;
	while (++j < colony->number_of_rooms)
		if (!ft_strcmp(colony->room_names[j]->room_name, to_add))
			break ;
	colony->room_names[i]->next[k] = colony->room_names[j];
	++colony->room_names[i]->number_of_link;
	free(cpy);
}

static	void	create_link(t_colony *colony, char *src, char *to_add)
{
	int		i;
	int		j;

	i = -1;
	while (++i < colony->number_of_rooms)
		if (!ft_strcmp(colony->room_names[i]->room_name, src))
			break ;
	if (!colony->room_names[i]->number_of_link)
	{
		if (!(colony->room_names[i]->next = (t_room **)malloc(sizeof(t_room *)
						* 1)))
			ft_malloc_error();
		j = -1;
		while (++j < colony->number_of_rooms)
			if (!ft_strcmp(colony->room_names[j]->room_name, to_add))
				break ;
		colony->room_names[i]->next[0] = colony->room_names[j];
		++colony->room_names[i]->number_of_link;
	}
	else
		relink_it(colony, src, to_add);
}

static	int		does_exist(t_colony *colony, char *s)
{
	int	i;

	i = -1;
	while (++i < colony->number_of_rooms)
	{
		if (!ft_strcmp(colony->room_names[i]->room_name, s))
			return (1);
	}
	return (0);
}

void			add_link(t_colony *colony)
{
	int			i;
	char		*src;
	char		*to_add;

	i = -1;
	while (++i < colony->number_of_pipes)
	{
		src = ft_strndup(colony->pipes[i], ft_strxlen(colony->pipes[i], '-'));
		to_add = ft_strdup(colony->pipes[i] +
				(ft_strxlen(colony->pipes[i], '-') + 1));
		if (does_exist(colony, src) && does_exist(colony, to_add))
		{
			create_link(colony, src, to_add);
			create_link(colony, to_add, src);
		}
		free(src);
		free(to_add);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:06:50 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/23 12:51:09 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int			get_room_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isalnum(line[i]))
		++i;
	return (i);
}

static	void		stock_it(t_colony *colony, char *line)
{
	char	**cpy;
	int		i;

	i = -1;
	cpy = colony->rooms;
	if (!(colony->rooms = (char **)malloc(sizeof(char *) *
					(colony->number_of_rooms + 1))))
		ft_malloc_error();
	while (++i < colony->number_of_rooms)
		colony->rooms[i] = cpy[i];
	colony->rooms[i] = ft_strndup(line, get_room_len(line));
	free(cpy);
}

static	int			check_duplicata(t_colony *colony, char *line)
{
	char	*s;
	int		i;

	i = -1;
	s = ft_strndup(line, ft_strxlen(line, 32));
	while (++i < colony->number_of_rooms)
		if (!ft_strcmp(s, colony->rooms[i]))
		{
			free(s);
			return (1);
		}
	free(s);
	return (0);
}

static	int			check_room(t_colony *colony, char *line)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	j += (line[i] && ft_isalnum(line[i]) && line[i] != 'L') ? 1 : 0;
	while (line[i] && ft_isalnum(line[i]))
		++i;
	i += (line[i] && line[i] == 32) ? 1 : 0;
	i += (line[i] && line[i] == '-') ? 1 : 0;
	j += (line[i] && ft_isdigit(line[i])) ? 1 : 0;
	while (line[i] && ft_isdigit(line[i]))
		++i;
	i += (line[i] && line[i] == 32) ? 1 : 0;
	i += (line[i] && line[i] == '-') ? 1 : 0;
	j += (line[i] && ft_isdigit(line[i])) ? 1 : 0;
	while (line[i] && ft_isdigit(line[i]))
		++i;
	if (line[i] || check_duplicata(colony, line))
		return (0);
	return (j == 3 ? 1 : 0);
}

int					stock_room(char *room, t_colony *colony, char *line)
{
	if (!ft_strcmp(room, "start"))
	{
		colony->processing_start = 0;
		colony->is_start_here = 1;
	}
	if (!ft_strcmp(room, "end"))
	{
		colony->processing_end = 0;
		colony->is_end_here = 1;
	}
	if (!check_room(colony, line))
		return (-1);
	if (!colony->number_of_rooms)
	{
		if (!(colony->rooms = (char **)malloc(sizeof(char *) * 1)))
			ft_malloc_error();
		colony->rooms[0] = ft_strndup(line, get_room_len(line));
	}
	else
		stock_it(colony, line);
	++colony->number_of_rooms;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:13:21 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/23 00:33:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static		int		get_start(t_colony *colony)
{
	if (colony->is_start_here)
		return (-1);
	colony->processing_end = 0;
	colony->processing_start = 1;
	return (0);
}

static		int		get_end(t_colony *colony)
{
	if (colony->is_end_here)
		return (-1);
	colony->processing_end = 1;
	colony->processing_start = 0;
	return (0);
}

int					get_nb_rooms(t_colony *colony, char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (get_start(colony));
	if (!ft_strcmp(line, "##end"))
		return (get_end(colony));
	if (ft_strlen(line) > 1 && line[0] == '#')
		return (0);
	if (check_pipes(line))
	{
		colony->got_rooms = 1;
		colony->got_pipe = 1;
		return (get_nb_pipes(colony, line));
	}
	if (colony->processing_start)
		return (stock_room("start", colony, line));
	if (colony->processing_end)
		return (stock_room("end", colony, line));
	return (stock_room("room", colony, line));
}

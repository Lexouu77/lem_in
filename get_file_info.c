/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:13:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/05/27 18:52:35 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void		get_commands(t_colony *colony, char *line)
{
	if (ft_strlen(line) >= 5 && line[2] == 'c' && line[3] == 'l' &&
			line[4] == 'r')
		colony->color = 1;
	if (ft_strlen(line) >= 5 && line[2] == 'd' && line[3] == 'n' &&
			line[4] == 'm')
		colony->display_nb_moves = 1;
	if (ft_strlen(line) >= 5 && line[2] == 'd' && line[3] == 'n' &&
			line[4] == 't')
		colony->display_nb_turns = 1;
	if (ft_strlen(line) >= 5 && line[2] == 'h' && line[3] == 'f' &&
			line[4] == 'i')
		colony->hide_file_info = 1;
	if (ft_strlen(line) >= 5 && line[2] == 'h' && line[3] == 'a' &&
			line[4] == 'm')
		colony->hide_ants_moves = 1;
}

static	void		delete_last_line(t_colony *colony)
{
	--colony->number_of_line;
	free(colony->file_info[colony->number_of_line]);
}

static	int			is_a_command(char *line)
{
	if (ft_strlen(line) > 2 && line[0] == '#' && line[1] == '#' &&
			ft_strcmp("##start", line) && ft_strcmp("##end", line))
		return (1);
	return (0);
}

void				get_file_info(t_colony *colony)
{
	char		*line;
	int			retour;

	while ((retour = get_next_line(0, &line)) > 0)
	{
		add_line(colony, line);
		if (is_a_command(line))
			get_commands(colony, line);
		if (!colony->got_nb_ants)
			retour = get_nb_ants(colony, line);
		else if (!colony->got_rooms)
			retour = get_nb_rooms(colony, line);
		else if (colony->got_rooms == 1)
			retour = get_nb_pipes(colony, line);
		else
			break ;
		if (retour == -1)
		{
			delete_last_line(colony);
			break ;
		}
	}
	free(line);
}

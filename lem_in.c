/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:58:03 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/26 11:56:44 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void		get_bonus(t_colony *colony, char *bonus)
{
	int	i;

	i = -1;
	while (bonus[++i])
	{
		if (bonus[i] == 'c')
			colony->color = 1;
		if (bonus[i + 1] && bonus[i] == 'n' && bonus[i + 1] == 'm')
			colony->display_nb_moves = 1;
		if (bonus[i + 1] && bonus[i] == 'n' && bonus[i + 1] == 't')
			colony->display_nb_turns = 1;
		if (bonus[i + 1] && bonus[i] == 'h' && bonus[i + 1] == 'i')
			colony->hide_file_info = 1;
		if (bonus[i + 1] && bonus[i] == 'h' && bonus[i + 1] == 'm')
			colony->hide_ants_moves = 1;
	}
}

static	void		set_end(t_colony *colony)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	l = -1;
	while (ft_strcmp("##end", colony->file_info[i]))
		++i;
	while (colony->file_info[i] && colony->file_info[i][0] == '#')
		++i;
	s = ft_strndup(colony->file_info[i], ft_strxlen(colony->file_info[i], 32));
	while (1)
		if (!ft_strcmp(s, colony->room_names[++l]->room_name))
			break ;
	colony->room_names[l]->is_end = 1;
	colony->end = colony->room_names[l];
	free(s);
}

static	void		set_start(t_colony *colony)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	l = -1;
	while (ft_strcmp("##start", colony->file_info[i]))
		++i;
	while (colony->file_info[i] && colony->file_info[i][0] == '#')
		++i;
	s = ft_strndup(colony->file_info[i], ft_strxlen(colony->file_info[i], 32));
	while (1)
		if (!ft_strcmp(s, colony->room_names[++l]->room_name))
			break ;
	colony->room_names[l]->is_start = 1;
	colony->start = colony->room_names[l];
	free(s);
}

static	t_colony	*init_colony(void)
{
	t_colony	*colony;

	if (!(colony = (t_colony*)malloc(sizeof(t_colony))))
		ft_malloc_error();
	colony->is_end_here = 0;
	colony->is_start_here = 0;
	colony->number_of_ants = 0;
	colony->number_of_ants_in_start = 0;
	colony->number_of_ants_in_end = 0;
	colony->number_of_rooms = 0;
	colony->number_of_paths = 0;
	colony->number_of_line = 0;
	colony->processing_start = 0;
	colony->processing_end = 0;
	colony->got_nb_ants = 0;
	colony->got_rooms = 0;
	colony->got_pipe = 0;
	colony->turns = 0;
	colony->moves = 0;
	colony->color = 0;
	colony->display_nb_moves = 0;
	colony->display_nb_turns = 0;
	colony->hide_file_info = 0;
	colony->hide_ants_moves = 0;
	return (colony);
}

int					main(int argc, char **argv)
{
	t_colony	*colony;

	colony = init_colony();
	colony->number_of_pipes = 0;
	if (argc == 2)
		get_bonus(colony, argv[1]);
	get_file_info(colony);
	if (!colony->got_nb_ants || !colony->got_rooms || !colony->got_pipe ||
			!colony->is_end_here || !colony->is_start_here)
		ft_error("ERROR");
	convert_info(colony);
	add_link(colony);
	set_start(colony);
	set_end(colony);
	if (check_info(colony))
		ft_error("ERROR");
	if (!colony->hide_file_info)
		ft_printf("%v\n", colony->file_info, colony->number_of_line);
	get_paths(colony);
	set_ants(colony);
	resolve(colony);
	return (0);
}

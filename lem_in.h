/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:58:04 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/26 11:57:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libftprintf/ft_printf.h"

typedef struct		s_ant
{
	int				number;
	int				is_at_end;
	char			**path_to_take;
	char			*actual_room;
}					t_ant;

typedef struct		s_room
{
	char			*room_name;
	char			is_end;
	char			is_start;
	char			is_full;
	int				weight;
	int				is_used;
	int				number_of_link;
	struct s_ant	*ant;
	struct s_room	**next;
}					t_room;

typedef struct		s_colony
{
	char			**path;
	char			**file_info;
	char			**rooms;
	char			**pipes;
	int				is_end_here;
	int				is_start_here;
	int				number_of_ants;
	int				number_of_ants_in_start;
	int				number_of_ants_in_end;
	int				number_of_rooms;
	int				number_of_paths;
	int				number_of_pipes;
	int				number_of_line;
	int				processing_start;
	int				processing_end;
	int				got_nb_ants;
	int				got_rooms;
	int				got_pipe;
	int				turns;
	int				moves;
	int				color;
	int				display_nb_moves;
	int				display_nb_turns;
	int				hide_file_info;
	int				hide_ants_moves;
	struct s_ant	**ants;
	struct s_room	**room_names;
	struct s_room	*start;
	struct s_room	*end;
}					t_colony;

void				add_link(t_colony *colony);

void				add_line(t_colony *colony, char *line);

int					check_info(t_colony *colony);

int					check_pipes(char *line);

void				convert_info(t_colony *colony);

void				get_file_info(t_colony *colony);

int					get_nb_ants(t_colony *colony, char *line);

int					get_nb_rooms(t_colony *colony, char *line);

int					get_nb_pipes(t_colony *colony, char *line);

void				get_paths(t_colony *colony);

void				move_ants(t_colony *colony);

void				resolve(t_colony *colony);

void				set_ants(t_colony *colony);

int					stock_room(char *room, t_colony *colony, char *line);

#endif

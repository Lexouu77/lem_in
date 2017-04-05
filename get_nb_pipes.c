/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:13:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/23 07:03:13 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void		copy_pipe(t_colony *colony, char *line)
{
	char	**cpy;
	int		i;

	i = -1;
	cpy = colony->pipes;
	if (!(colony->pipes = (char **)malloc(sizeof(char *) *
					(colony->number_of_pipes + 1))))
		ft_malloc_error();
	while (++i < colony->number_of_pipes)
		colony->pipes[i] = cpy[i];
	colony->pipes[i] = ft_strdup(line);
	free(cpy);
}

int					get_nb_pipes(t_colony *colony, char *line)
{
	if (ft_strlen(line) > 1 && line[0] == '#')
		return (0);
	if (!check_pipes(line))
		return (-1);
	if (!colony->number_of_pipes)
	{
		if (!(colony->pipes = (char **)malloc(sizeof(char *) * 1)))
			ft_malloc_error();
		colony->pipes[0] = ft_strdup(line);
	}
	else
		copy_pipe(colony, line);
	++colony->number_of_pipes;
	return (1);
}

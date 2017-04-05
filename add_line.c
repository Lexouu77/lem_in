/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:52:27 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/22 17:31:08 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	copy_line(t_colony *colony, char *line)
{
	char	**cpy;
	int		i;

	i = -1;
	cpy = colony->file_info;
	if (!(colony->file_info = (char **)malloc(sizeof(char *) *
					(colony->number_of_line + 1))))
		ft_malloc_error();
	while (++i < colony->number_of_line)
		colony->file_info[i] = cpy[i];
	colony->file_info[i] = ft_strdup(line);
	free(cpy);
}

void			add_line(t_colony *colony, char *line)
{
	if (!colony->number_of_line)
	{
		if (!(colony->file_info = (char **)malloc(sizeof(char *) * 1)))
			ft_malloc_error();
		colony->file_info[0] = ft_strdup(line);
		++colony->number_of_line;
		return ;
	}
	copy_line(colony, line);
	++colony->number_of_line;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:12:39 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/22 21:51:21 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_nb_ants(t_colony *colony, char *line)
{
	int		i;

	i = -1;
	if (ft_strlen(line) > 1 && line[0] == '#')
		return (0);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (-1);
	colony->number_of_ants = ft_atoi(line);
	if (colony->number_of_ants <= 0)
		return (-1);
	colony->got_nb_ants = 1;
	return (0);
}

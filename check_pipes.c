/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:23:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/22 21:43:08 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					check_pipes(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	j += (line[i] && ft_isalnum(line[i]) && line[i] != 'L') ? 1 : 0;
	while (line[i] && ft_isalnum(line[i]))
		++i;
	j += (line[i] && line[i] == '-') ? 1 : 0;
	i += (line[i] && line[i] == '-') ? 1 : 0;
	j += (line[i] && ft_isalnum(line[i]) && line[i] != 'L') ? 1 : 0;
	while (line[i] && ft_isalnum(line[i]))
		++i;
	if (line[i])
		return (0);
	return (j == 3 ? 1 : 0);
}

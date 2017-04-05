/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:38:57 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 18:23:08 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					resolve(t_colony *colony)
{
	colony->number_of_ants_in_start = colony->number_of_ants;
	while (colony->number_of_ants_in_end != colony->number_of_ants)
	{
		move_ants(colony);
		if (!colony->hide_ants_moves)
			ft_printf("\n");
		++colony->turns;
	}
	if (colony->display_nb_moves)
		ft_printf("moves required : [%[[FG_RED,SP_RST]d]\n", colony->moves);
	if (colony->display_nb_turns)
		ft_printf("Turns required : [%[[FG_GRE,SP_RST]d]\n", colony->turns);
}

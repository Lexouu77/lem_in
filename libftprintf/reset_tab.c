/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 07:12:33 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/27 07:33:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reset_min_area_size(t_flags *flag)
{
	flag->i = -1;
	while (++flag->i < 10)
		flag->min_area_size[flag->i] = 0;
}

void		reset_precision(t_flags *flag)
{
	flag->i = -1;
	while (++flag->i < 10)
		flag->precision[flag->i] = 0;
}

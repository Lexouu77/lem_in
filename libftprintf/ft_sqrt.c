/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:28:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 03:28:30 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb == 0)
		return (0);
	i = nb;
	while ((unsigned int)nb < (i * i))
		--i;
	if ((unsigned int)nb == (i * i))
		return (i);
	return (0);
}

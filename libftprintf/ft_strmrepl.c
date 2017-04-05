/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmrepl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:15:02 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 03:15:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strmrepl(char *src, char *to_find, char c)
{
	while (*to_find)
		ft_strrepl(src, *to_find++, c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 02:23:55 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 02:24:41 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_occ;

	last_occ = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			last_occ = (char *)s;
		++s;
	}
	if (!*s && *s == (char)c)
		last_occ = (char *)s;
	return (last_occ);
}

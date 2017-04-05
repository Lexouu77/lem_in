/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 03:12:05 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/11 03:12:28 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_digits(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		++i;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	u_nbr;

	len = count_digits(n);
	u_nbr = n;
	if (n < 0)
	{
		u_nbr = -n;
		++len;
	}
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	str[--len] = u_nbr % 10 + '0';
	while (u_nbr /= 10)
		str[--len] = u_nbr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

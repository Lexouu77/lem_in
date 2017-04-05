/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 03:19:19 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/25 10:09:11 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list		va;
	char		*format_cpy;
	int			i;
	t_info		*list;

	if (!format)
	{
		ft_putendl("first parameter is NULL, please don't do this.");
		return (-1);
	}
	format_cpy = ft_strdup(format);
	if (!(list = (t_info*)malloc(sizeof(t_info))))
		ft_malloc_error();
	va_start(va, format);
	list->nb_c_written = 0;
	list->nb_c_needed = 0;
	list->tmp = NULL;
	list->converted_string = NULL;
	i = display(format_cpy, &va, list);
	write(1, list->converted_string, i);
	free(list->converted_string);
	free(list);
	va_end(va);
	free(format_cpy);
	return (i);
}

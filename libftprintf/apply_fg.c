/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:05:30 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/06 16:48:54 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_fg(char *s, t_info *list)
{
	if (*s == 'R' && *(s + 1) == 'E' && *(s + 2) == 'D')
		bufferjoin(list, ANSI_FG_RED, 6);
	else if (*s == 'G' && *(s + 1) == 'R' && *(s + 2) == 'E')
		bufferjoin(list, ANSI_FG_GREEN, 6);
	else if (*s == 'Y' && *(s + 1) == 'E' && *(s + 2) == 'L')
		bufferjoin(list, ANSI_FG_YELLOW, 6);
	else if (*s == 'B' && *(s + 1) == 'L' && *(s + 2) == 'U')
		bufferjoin(list, ANSI_FG_BLUE, 6);
	else if (*s == 'M' && *(s + 1) == 'A' && *(s + 2) == 'G')
		bufferjoin(list, ANSI_FG_MAGENTA, 6);
	else if (*s == 'C' && *(s + 1) == 'Y' && *(s + 2) == 'A')
		bufferjoin(list, ANSI_FG_CYAN, 6);
	else if (*s == 'W' && *(s + 1) == 'H' && *(s + 2) == 'I')
		bufferjoin(list, ANSI_FG_WHITE, 6);
	return (s + 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 04:21:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/03/14 04:21:49 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*next_lst;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		next_lst = list->next;
		ft_lstdelone(&list, del);
		list = next_lst;
	}
	*alst = NULL;
}

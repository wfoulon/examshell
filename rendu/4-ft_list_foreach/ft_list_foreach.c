/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:24:05 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/15 11:25:58 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t-list	*list;

	list = begin_list;
	while (list)
	{
		(*f)(list->data);
		list = list->next;
	}
}


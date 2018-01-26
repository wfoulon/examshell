/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:11:37 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/26 14:16:39 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int *cmp())
{
	t_list	*list;
	t_list	*tmp;

	while (*begin_list && (cmp(*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (cmp(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		if (list->next)
			list = list->next;
	}
}

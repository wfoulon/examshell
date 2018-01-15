/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:28:20 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/05 15:32:58 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_size.h"

int		ft_list_size(t_list *begin_list)
{
	int i;
	t_list *list;

	i = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

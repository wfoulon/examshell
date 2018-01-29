/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:12:03 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/15 11:16:51 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_swap(int *a, int*b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
	}
}

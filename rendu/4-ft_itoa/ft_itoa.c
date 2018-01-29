/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:58:22 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/29 14:05:26 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		int_len(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

long	max_power(long nb)
{
	long pwr;

	pwr = 10;
	while (pwr < nb)
	{
		if (!(pwr * 10))
			break;
		pwr *= 10;
	}
	if (pwr > nb)
		pwr /= 10;
	return (pwr);
}

char	*ft_itoa(int nbr)
{
	long	nb;
	long	pwr;
	char	*ptr;
	int		i;

	i = 0;
	nb = (long)nbr;
	ptr = (char *)malloc(sizeof(char) * int_len(nbr) + 1);
	if (nb < 0)
	{
		nb = -nb;
		ptr[i] = '-';
		i++;
	}
	pwr = max_power(nb);
	while (pwr > 0)
	{
		ptr[i] = nb / pwr + 48;
		nb %= pwr;
		pwr /= 10;
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

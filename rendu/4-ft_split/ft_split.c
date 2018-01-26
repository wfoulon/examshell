/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:35:27 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/26 12:46:45 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		ft_isprint(char c)
{
	return(c >= ' ' && c <= '~');
}

int		ft_isgraph(char c)
{
	return (c > ' ' && c <= '~');
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	j = 0;
	tab = (char **)malloc(sizeof((char) * ft_strlen(str) + 1));
	while (str[i])
	{
		if (ft_isgraph(str[i]))
		{
			tab[j][k] = str[i];
			i++;
			k++;
		}
		if (ft_isspace(str[i]))
		{
			i++;
			j++;
			k = 0;
		}
	}
	tab[j + 1] = NULL;
	return (tab);
}

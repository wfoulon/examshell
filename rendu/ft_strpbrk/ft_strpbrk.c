/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:39:58 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/15 13:01:29 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int i;
	char a;

	i = 0;
	a = (char)c;

	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		else
			i++;
	}
	while (s[i] == a)
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char		*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (ft_strchr(s2, (int)*s1))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}

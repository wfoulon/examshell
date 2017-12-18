/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:01:59 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:06 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

size_t		ft_strcspn(const char *s1, cont char *s2)
{
	const char *s1r;
	const char *s2r;

	*s1r = *s1;
	while (*s1r)
	{
		s2r = s2;
		while (*s2r)
		{
			if (*s1r == *s2r++)
				return (s1r - s1);
		}
		s1r++;
	}
	return (s1r - s1);
}

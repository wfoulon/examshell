/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:13:05 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/04 14:56:04 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') &&  (str[i + 1] == ' ' ||
				str[i + 1] == '\t' || !str[i + 1] || str[i + 1] == '\n' ||
				str[i + 1] == '\r' || str[i + 1] == '\f' || str[i + 1] == '\v'))
		{
			str[i] -= 32;
			ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			rstr_capitalizer(*argv);
			ft_putchar('\n');
			argv++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}

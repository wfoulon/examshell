/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:25:17 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/04 11:46:40 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_rotone(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + 1;
			i++;
		}
		else if (str[i] == 'z')
		{
			str[i] = 'a';
			i++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Y')
		{
			str[i] = str[i] + 1;
			i++;
		}
		else if (str[i] == 'Z')
		{
			str[i] = 'A';
			i++;
		}
		else
			i++;
	}
	ft_putstr(str);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	else
	{
		ft_rotone(argv[1]);
		ft_putchar('\n');
	}
	return (0);
}

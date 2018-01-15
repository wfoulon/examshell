/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:21:04 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/05 16:26:08 by wfoulon          ###   ########.fr       */
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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void print_string(char *str)
{
	int i;

	i = 0;
	while (str[i] <= ' ' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		while (str[i] > ' ')
		{
			ft_putchar(str[i]);
			i++;
		}
		while (str[i] <= ' ' && str[i] != '\0')
			i++;
		if (str[i - 1] <= ' ' && str[i - 1] != '\0' && ft_strlen(str) > i)
			ft_putstr("   ");
	}
	ft_putchar('\n');
}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_string(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
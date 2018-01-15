/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:45:44 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/05 12:15:30 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar('0' + num);
}

int		main(int ac, char **av)
{
	int res;

	res = 0;
	if (ac != 4)
	{
		ft_putchar('\n');
		return (0);
	}
	if (*av[2] == '*')
		res = atoi(av[1]) * atoi(av[3]);
	else if (*av[2] == '/')
		res = atoi(av[1]) / atoi(av[3]);
	else if (*av[2] == '+')
		res = atoi(av[1]) + atoi(av[3]);
	else if (*av[2] == '-')
		res = atoi(av[1]) - atoi(av[3]);
	else if (*av[2] == '%')
		res = atoi(av[1]) % atoi(av[3]);
	ft_putnbr(res);
	ft_putchar('\n');
	return (0);
}

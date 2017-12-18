/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:06:30 by wfoulon           #+#    #+#             */
/*   Updated: 2017/12/15 14:23:38 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int result;

	i = 0;
	neg = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-result);
	else
		return (result);
}

int		power(int nb)
{
	int power;

	power = 16;
	while (power < nb)
		power = power * 16;
	if (power > nb)
		power = power / 16;
	return (power);
}

void	print_hex(int nb)
{
	int		pwr;
	int		index;
	int		rest;
	char	*hex;

	hex = "0123456789abcdef";
	pwr = power(nb);
	while (pwr > 0)
	{
		index = nb / pwr;
		rest = nb % pwr;
		write(1, &hex[index], 1);
		pwr = pwr / 16;
		nb = rest;
	}
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		if (n == 0)
		{
			write(1, "0\n", 1);
			return (0);
		}
	print_hex(n);
	}
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:28:11 by wfoulon           #+#    #+#             */
/*   Updated: 2018/01/05 11:28:13 by wfoulon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	last;
	unsigned char	reversed;

	i = 0;
	while (i < 7)
	{
		last = octet & 1;
		octet >>= 1;
		reversed += last;
		reversed <<= 1;
		i++;
	}
	return (reversed);
}

void		print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (i & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

int main(int argc, const char *argv[])
{
	print_bits(reverse_bits((unsigned char)123));
	return 0;
}
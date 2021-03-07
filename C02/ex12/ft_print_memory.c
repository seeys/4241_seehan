/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:50:53 by seehan            #+#    #+#             */
/*   Updated: 2021/03/07 17:22:16 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_str(unsigned char *str)
{
	int i;

	i = 0;
	while (i < 16 && str[i])
	{
		if (!((str[i] >= 0 && str[i] <= 32) || str[i] == 127))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	ft_put_space(int check)
{
	while (check < 40)
	{
		write(1, " ", 1);
		check++;
	}
}

void	ft_print_hex(unsigned char *str)
{
	char	*base;
	int		i;
	int		check;

	check = 0;
	i = 0;
	base = "0123456789abcdef";
	while (i < 16 && str[i])
	{
		write(1, &base[str[i] / 16], 1);
		write(1, &base[str[i] % 16], 1);
		if (i % 2 == 1)
		{
			write(1, " ", 1);
			check++;
		}
		i++;
		check += 2;
	}
	if (!str[i])
		ft_put_space(check);
}

void	ft_print_addr(unsigned long tmp)
{
	char	*base;
	int		j;
	char	tab[15];

	j = 0;
	while (j <= 14)
		tab[j++] = '0';
	j--;
	base = "0123456789abcdef";
	while (tmp >= 16)
	{
		tab[j--] = base[tmp % 16];
		tmp = tmp / 16;
	}
	j = 0;
	while (j <= 14)
		write(1, &tab[j++], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned long	tmp;

	i = 0;
	while (i < size)
	{
		tmp = (unsigned long)&addr[i];
		ft_print_addr(tmp);
		write(1, ": ", 2);
		ft_print_hex((unsigned char *)addr + i);
		ft_put_str((unsigned char *)addr + i);
		i += 16;
		write(1, "\n", 1);
	}
	return (addr);
}

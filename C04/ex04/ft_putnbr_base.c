/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:59:21 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 18:18:44 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		base_is_invalid(char *base)
{
	int i;
	int m;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		m = i + 1;
		while (base[m])
			if (base[m++] == base[i])
				return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int value;
	int len;

	if (base_is_invalid(base))
		return ;
	len = ft_strlen(base);
	value = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		value = -nbr;
	}
	if (value >= len)
	{
		ft_putnbr_base(value / len, base);
		ft_putnbr_base(value % len, base);
	}
	else
		write(1, &base[value], 1);
}

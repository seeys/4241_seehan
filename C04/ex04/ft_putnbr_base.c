/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:59:21 by seehan            #+#    #+#             */
/*   Updated: 2021/03/08 17:33:44 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				base_is_invalid(char *base)
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

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int value;
	unsigned int len;

	if (base_is_invalid(base))
		return ;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		value = -(unsigned int)nbr;
	}
	else
		value = nbr;
	if (value < len)
		ft_putchar(base[value]);
	else
	{
		ft_putnbr_base(value / len, base);
		ft_putchar(base[value % len]);
	}
}

int main(void)
{
	ft_putnbr_base(123, "0123456789");
	printf("\n");
	ft_putnbr_base(-10, "01");
	printf("\n");
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	printf("\n");
	ft_putnbr_base(0, "0123456789abcdef");
	return (0);
}

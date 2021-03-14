/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:00:12 by seehan            #+#    #+#             */
/*   Updated: 2021/03/14 14:08:03 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (0);
		m = i + 1;
		while (base[m])
			if (base[m++] == base[i])
				return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
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

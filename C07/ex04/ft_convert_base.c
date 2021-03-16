/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:00:12 by seehan            #+#    #+#             */
/*   Updated: 2021/03/16 00:12:45 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		str_check(char *str, char *base);
int		base_check(char *base);
char	*ft_putnbr_base(int nbr, char *base, int i, char *tab);

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * (ft_recursive_power(nb, power - 1)));
}

char	*ft_swaptab(char *tab)
{
	int				i;
	char			tmp;
	int				size;

	size = ft_strlen(tab);
	i = 0;
	while (i < size / 2 && size >= 1)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
	return (tab);
}

char	*ft_malloc(int nbr, char *base_to)
{
	int		i;
	int		nb;
	char	*tab;

	i = 0;
	nb = nbr;
	while (nb)
	{
		nb = nb / ft_strlen(base_to);
		i++;
	}
	if (!(tab = malloc(sizeof(char) * i + 2 * sizeof(char) + 2)))
		return (0);
	if (nbr < 0)
		tab[i] = '-';
	return (ft_swaptab(ft_putnbr_base(nbr, base_to, 0, tab)));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		i;
	int		j;
	int		count;
	int		value;

	i = 0;
	value = 0;
	count = str_check(nbr, base_from);
	sign = 1;
	if (!(base_check(base_from)) || !(base_check(base_to)))
		return (NULL);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		sign = (nbr[i++] == '-') ? -sign : sign;
	while (--count >= 0 && base_check(base_from))
	{
		j = 0;
		while (nbr[i] != base_from[j])
			j++;
		value = value + (ft_recursive_power(ft_strlen(base_from), count) * j);
		i++;
	}
	return (ft_malloc(value * sign, base_to));
}

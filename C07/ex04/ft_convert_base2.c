/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:00:26 by seehan            #+#    #+#             */
/*   Updated: 2021/03/14 22:07:31 by seehan           ###   ########.fr       */
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

int				str_check(char *str, char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (base[j])
	{
		j = 0;
		while (base[j] != str[i] && base[j] != '\0')
			j++;
		if (base[j] == str[i] && str[i] != '\0')
			count = count + 1;
		i++;
	}
	return (count);
}

int				base_check(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[i] != base[j] && base[j] != '\0')
			j++;
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_putnbr_base(int nbr, char *base, int i, char *tab)
{
	unsigned int	value;

	if (!base_check(base))
		return (0);
	if (nbr < 0)
		value = -(unsigned int)nbr;
	else
		value = nbr;
	if (value < ft_strlen(base))
	{
		tab[i] = (base[value]);
		i++;
		if (tab[i] == '-')
			i++;
		tab[i] = '\0';
	}
	else
	{
		tab[i] = base[value % ft_strlen(base)];
		ft_putnbr_base(value / ft_strlen(base), base, ++i, tab);
	}
	return (tab);
}

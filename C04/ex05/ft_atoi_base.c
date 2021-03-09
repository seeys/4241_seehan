/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:38:21 by seehan            #+#    #+#             */
/*   Updated: 2021/03/09 21:18:34 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int		str_check(char *str, char *base)
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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		base_is_valid(char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int j;
	int len;
	int value;

	i = 0;
	value = 0;
	if (!base_is_valid(base))
		return (0);
	len = str_check(str, base);
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -sign : sign;
	while (--len >= 0)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		value = value + (ft_recursive_power(ft_strlen(base), len) * j);
		i++;
	}
	return (value * sign);
}

int 	main(void)
{
	printf("==== 21 ft_atoi_base ====\n");
	printf("Tesing ex21\n");
	printf("Should return 0 in case of invalid arguments\n");
	printf("%d\n", ft_atoi_base("15", ""));
	printf("%d\n", ft_atoi_base("15", "1"));
	printf("%d\n", ft_atoi_base("15", "144"));
	printf("%d\n", ft_atoi_base("15", "14+35"));
	printf("%d\n", ft_atoi_base("15", "145-09"));
	printf("%d\n", ft_atoi_base("", "14509"));
	printf("%d\n", ft_atoi_base("x15", "14509"));
	printf("Should print number in correct radix\n");
	printf("%d\n", ft_atoi_base("+1111", "01"));
	printf("%d\n", ft_atoi_base("+15", "0123456789"));
	printf("%d\n", ft_atoi_base("+F", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("+vi", "fivte3n"));
	printf("%d\n", ft_atoi_base("+84", "9876543210"));
	printf("Should handle negative numbers\n");
	printf("%d\n", ft_atoi_base("-1111", "01"));
	printf("%d\n", ft_atoi_base("-15", "0123456789"));
	printf("%d\n", ft_atoi_base("-F", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-ve", "fivte3n"));
	printf("%d\n", ft_atoi_base("-84", "9876543210"));
	printf("All tests passed for ex21\n");
	return (0);
}

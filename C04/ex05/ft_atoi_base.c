/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:19:28 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 18:50:01 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int len;
	int idx;
	int result;

	if (base_is_invalid(base))
		return (0);
	sign = 1;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	len = ft_strlen(base);
	while (is_in_base(*str, base) && *str)
	{
		idx = is_in_base(*str++, base) - 1;
		result = result * len + idx;
	}
	return (result * sign);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_space(char c)
{
	int		i;
	char	*spaces;

	spaces = " \f\n\r\t\v";
	i = -1;
	while (spaces[++i] != '\0')
		if (c == spaces[i])
			return (1);
	return (0);
}

int		is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i] != '\0')
		if (c == base[i])
			return (i + 1);
	return (0);
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

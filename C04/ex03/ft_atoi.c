/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:45:06 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 18:59:49 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int value;
	int sign;

	value = 0;
	sign = 1;
	while ((*str <= 9 && *str >= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= 1;
	}
	while (*str >= '0' && *str <= '9')
		value = (value * 10) + (sign * ((*str++) - '0'));
	return (value);
}

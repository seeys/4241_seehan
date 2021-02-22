/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:18:43 by seehan            #+#    #+#             */
/*   Updated: 2021/02/22 16:47:15 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_len;
char g_arr[10];

void	ft_back(int pos, int m)
{
	int j;

	if (m == g_len)
	{
		write(1, g_arr, g_len);
		write(1, ", ", 2);
		return ;
	}
	if (pos == 9)
		return ;
	j = pos;
	while (++j <= 10 - g_len + m)
	{
		g_arr[m] = '0' + j;
		ft_back(j, m + 1);
	}
}

void	ft_last(int i)
{
	char c;

	while (i <= 9)
	{
		c = '0' + i++;
		write(1, &c, 1);
	}
}

void	ft_print_combn(int n)
{
	int i;

	i = 0;
	g_len = n;
	while (i < 10 - n)
	{
		g_arr[0] = '0' + i;
		ft_back(i++, 1);
	}
	ft_last(i);
}

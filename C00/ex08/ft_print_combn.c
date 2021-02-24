/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:34:09 by seehan            #+#    #+#             */
/*   Updated: 2021/02/24 17:00:32 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_data[10];
int		g_r;

void	ft_print_num(int start, int idx)
{
	int i;

	if (idx == g_r)
	{
		write(1, g_data, g_r);
		write(1, ", ", 2);
		return ;
	}
	if (start == 9)
		return ;
	i = start;
	while (++i <= 10 - g_r + idx)
	{
		g_data[idx] = '0' + i;
		ft_print_num(i, idx + 1);
	}
}

void	ft_print_last(int i)
{
	char c;
	
	while (i < 10)
	{
		c = '0' + i++;
		write(1, &c, 1);
	}
}

void	ft_print_combn(int n)
{
	int i;

	i = 0;
	g_r = n;
	while (i < 10 - n)
	{
		g_data[0] = '0' + i;
		ft_print_num(i, 1);
		i++;
	}
	ft_print_last(i);
}

int		main(void)
{
	ft_print_combn(4);
	return (0);
}

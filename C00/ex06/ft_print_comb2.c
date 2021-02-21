/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:17:00 by seehan            #+#    #+#             */
/*   Updated: 2021/02/21 21:34:01 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		f_num;
	int		b_num;

	f_num = 0;
	while (f_num <= 98)
	{
		b_num = f_num + 1;
		while (j <= 99)
		{
			ft_putchar((i / 10) + 48);
			ft_putchar((i % 10) + 48);
			ft_putchar(' ');
			ft_putchar((j / 10) + 48);
			ft_putchar((j % 10) + 48);
			if (f_num != 98 || b_num != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b_num++;
		}
		f_num++;
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}

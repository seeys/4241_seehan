/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwon <dokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:34:43 by dokwon            #+#    #+#             */
/*   Updated: 2021/02/20 11:49:30 by dokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int now_x;
	int now_y;

	now_y = 1;
	while (now_y <= y)
	{
		now_x = 1;
		while (now_x <= x)
		{
			if (now_x == 1 && now_y == 1)
				ft_putchar('A');
			else if ((now_x != 1 && now_y != 1) && (now_x == x && now_y == y))
				ft_putchar('A');
			else if ((now_x == x && now_y == 1) || (now_x == 1 && now_y == y))
				ft_putchar('C');
			else if ((now_x == x || now_x == 1) || (now_y == 1 || now_y == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
			now_x++;
		}
		ft_putchar('\n');
		now_y++;
	}
}

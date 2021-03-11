/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:11:12 by seehan            #+#    #+#             */
/*   Updated: 2021/03/09 18:33:32 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int i;
	int j;

	i = ac - 1;
	while (i > 0)
	{
		j = 0;
		while (av[i][j])
		{
			ft_putchar(av[i][j]);
			j++;
		}
		write(1,"\n",1);
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:39:06 by seehan            #+#    #+#             */
/*   Updated: 2021/03/13 21:40:54 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tmp;

	tmp = NULL;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(tmp = malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (i < max - min)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (max - min);
}

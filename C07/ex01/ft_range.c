/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:23:06 by seehan            #+#    #+#             */
/*   Updated: 2021/03/13 21:38:15 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
		return (0);
	if (!(tab = malloc(sizeof(*tab) * (max - min))))
		return (0);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 00:57:41 by seehan            #+#    #+#             */
/*   Updated: 2021/02/22 00:59:34 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i;

	i = 0;
	while (i < --size)
	{
		temp = tab[i];
		tab[i++] = tab[size];
		tab[size] = temp;
	}
}

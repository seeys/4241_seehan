/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 23:57:37 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 23:58:46 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		result = 1;
		while (nb)
			result = result * nb--;
	}
	return (result);
}

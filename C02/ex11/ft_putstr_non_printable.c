/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:47:32 by seehan            #+#    #+#             */
/*   Updated: 2021/02/25 23:30:50 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	is_not_word(char *str)
{
	char hex;
	
	hex = "0123456789abcdef";

}
void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str >= 0 && *str <= 32) || *str == 127)
			is_not_word(*str);
		else
		{
			write(1, str, 1);
		}
		str++;
}


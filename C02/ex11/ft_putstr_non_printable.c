/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:47:32 by seehan            #+#    #+#             */
/*   Updated: 2021/03/07 15:30:51 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	is_not_word(unsigned char str)
{
	write(1, "\\", 1);
	ft_putchar("0123456789abcdef"[str / 16]);
	ft_putchar("0123456789abcdef"[str % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			is_not_word(*str);
		else
			write(1, str, 1);
		str++;
	}
}

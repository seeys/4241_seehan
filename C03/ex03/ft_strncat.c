/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:20:54 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 17:22:11 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *p;

	p = dest;
	while (*dest)
		dest++;
	while (*src && nb-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}

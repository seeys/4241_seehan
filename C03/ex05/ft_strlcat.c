/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:26:31 by seehan            #+#    #+#             */
/*   Updated: 2021/03/09 16:54:29 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int d_len;
	unsigned int result;
	unsigned int i;

	d_len = 0;
	while (dest[d_len] != '\0')
		d_len++;
	result = 0;
	while (src[result])
		result++;
	if (size <= d_len)
		result = result + size;
	else
		result = result + d_len;
	i = 0;
	while (src[i] != '\0' && d_len + 1 < size)
	{
		dest[d_len] = src[i];
		d_len++;
		i++;
	}
	dest[d_len] = '\0';
	return (result);
}

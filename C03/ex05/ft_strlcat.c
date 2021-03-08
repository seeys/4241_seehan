/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:26:31 by seehan            #+#    #+#             */
/*   Updated: 2021/03/08 17:13:58 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
	while (src[i] != '\0' && d_len + 1 <size)
	{
		dest[d_len] = src[i];
		d_len++;
		i++;
	}
	dest[d_len] = '\0';
	return (result);
}

int main(void)
{
	char s1[5];
	char s2[4] = "abc";
	char s3[5];
	char s4[4] = "abc";
	printf("%u", ft_strlcat(s1,s2,2));
	printf("%lu", strlcat(s3,s4,2));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:22:29 by seehan            #+#    #+#             */
/*   Updated: 2021/03/06 17:23:55 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *i;
	char *j;

	if (!*to_find)
		return (str);
	while (*str)
	{
		i = str;
		j = to_find;
		while (*j && *i == *j)
		{
			i++;
			j++;
		}
		if (*j == 0)
			return (str);
		str++;
	}
	return (0);
}

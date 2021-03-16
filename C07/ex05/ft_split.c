/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:00:55 by seehan            #+#    #+#             */
/*   Updated: 2021/03/16 14:18:29 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_charset(char c, char *charset)
{
	int			i;

	i = 0;
	while (c != charset[i] && charset[i] != '\0')
		i++;
	if (charset[i] != '\0')
		return (0);
	return (1);
}

int				ft_len(char *str, int i, char *charset)
{
	int			j;

	j = 0;
	while (ft_charset(str[i], charset) && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int				ft_nbr_tok(char *str, char *charset)
{
	int			i;
	int			nbr_tok;

	i = 0;
	nbr_tok = 0;
	while (str[i] && charset[0])
	{
		while (ft_charset(str[i], charset) == 0)
			i++;
		if (str[i])
			nbr_tok++;
		while (ft_charset(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	if (!(charset[0]))
		return (1);
	return (nbr_tok);
}

char			**ft_split(char *str, char *charset)
{
	int			is;
	int			i;
	int			j;
	char		**tab;

	is = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char*) * (ft_nbr_tok(str, charset) + 1))))
		return (0);
	while (i < ft_nbr_tok(str, charset) && str[0] != '\0')
	{
		j = 0;
		while (ft_charset(str[is], charset) == 0 && str[is])
			is++;
		if (!(tab[i] = malloc(sizeof(char) * ft_len(str, is, charset) + 1)))
			return (0);
		while (ft_charset(str[is], charset) == 1 && str[is])
			tab[i][j++] = str[is++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

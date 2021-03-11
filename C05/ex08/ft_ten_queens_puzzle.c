/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:32:07 by seehan            #+#    #+#             */
/*   Updated: 2021/03/09 17:37:25 by seehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *board)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	write(1, "\n", 1);
}

int		ft_check(int *board, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		if (board[i] == board[c])
			return (0);
		if (board[c] == board[i] - (c - i) || board[i] == board[c] + (c - i))
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(int *board, int col, int *cnt)
{
	int row;

	if (col == 10)
	{
		*cnt = *cnt + 1;
		ft_print(board);
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			board[col] = row;
			if (ft_check(board, col))
				ft_backtrack(board, col + 1, cnt);
			row++;
		}
		board[col] = 0;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int board[10];
	int cnt;

	i = 0;
	cnt = 0;
	while (i < 10)
		board[i++] = 0;
	ft_backtrack(board, 0, &cnt);
	return (cnt);
}

int main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}

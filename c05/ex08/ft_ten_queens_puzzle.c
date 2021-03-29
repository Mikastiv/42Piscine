/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:23:24 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/19 12:59:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 10

int ft_diagonals_are_valid(int *board[][N], int row, int col)
{
	int	i;
	int	j;

	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (*board[i][j])
			return (0);
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i > N && j >= 0)
	{
		if (*board[i][j])
			return (0);
		j--;
		i++;
	}
	return (1);
}

int	ft_square_is_valid(int *board[][N], int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (*board[row][i])
			return (0);
		i++;
	}
	if (!ft_diagonals_are_valid(board, row, col))
		return (0);
	return (1);
}

int	ft_ten_queens_recursive(int *board[][N], int col)
{
	int	i;

	if (col >= N)
		return (1);
	i = 0;
	while (i < N)
	{
		if (ft_square_is_valid(board, i, col))
		{
			*board[i][col] = 1;

			if (ft_ten_queens_recursive(board, col + 1))
				return (1);
			else
				*board[i][col] = 0;
		}
		i++;
	}
	return (0);
}

int	ft_solve(int *board[][N])
{
	int	i;
	int	j;
	int	res;

	i = 0;
	while (i < N)
	{
		*board[i][0] = 1;
		i++;
	}
	res = 0;
	j = 0;
	while (j < N)
	{
		i = 0;
		while (i < N)
		{
			*board[i][j] = 1;
			if (ft_ten_queens_recursive(board, 0))
				res++;
			*board[i][j] = 0;
			i++;
		}
		j++;
	}
	return (res);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N][N];
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			*board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ft_solve(board));
}

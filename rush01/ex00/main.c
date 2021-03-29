/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 09:37:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 16:43:16 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "input_validation.h"
#include "array_initialization.h"
#include "column_validation.h"
#include "row_validation.h"
#include "print.h"

int	ft_is_number_valid(int result[][N], int clues[][N], int row, int col)
{
	if (!ft_rowleft_first_col_valid(result, clues[2][row], row, col))
		return (0);
	if (!ft_rowright_first_col_valid(result, clues[3][row], row, col))
		return (0);
	if (!ft_colup_first_row_valid(result, clues[0][col], row, col))
		return (0);
	if (!ft_coldown_first_row_valid(result, clues[1][col], row, col))
		return (0);
	if (ft_dup_in_row(result, row))
		return (0);
	if (ft_dup_in_col(result, col))
		return (0);
	if (!ft_is_rowleft_valid(result, clues[2][row], row))
		return (0);
	if (!ft_is_colup_valid(result, clues[0][col], col))
		return (0);
	if (row == N - 1 && !ft_is_rowright_valid(result, clues[3][row], row))
		return (0);
	if (col == N - 1 && !ft_is_coldown_valid(result, clues[1][col], col))
		return (0);
	return (1);
}

void	ft_find_next_number(int result[][N], int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (result[i][j] == 0)
			{
				*row = i;
				*col = j;
				return ;
			}
			j++;
		}
		i++;
	}
	*row = -1;
	*col = -1;
}

int	ft_solve(int result[][N], int clues[][N])
{
	int	row;
	int	col;
	int	num;

	ft_find_next_number(result, &row, &col);
	if (row == -1 && col == -1)
		return (1);
	num = 1;
	while (num <= N)
	{
		result[row][col] = num;
		if (ft_is_number_valid(result, clues, row, col))
		{
			if (ft_solve(result, clues))
				return (1);
		}
		result[row][col] = 0;
		num++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	clues[4][N];
	int	res[N][N];

	if (argc != 2 || !ft_input_is_valid(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_parse_input(clues, argv[1]);
	ft_init_result_array(res);
	if (ft_solve(res, clues))
		ft_print_array(res);
	else
		ft_putstr("Error\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:30:37 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 16:20:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "row_validation.h"

int	ft_dup_in_row(int result[][N], int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (result[row][i] != 0 && result[row][j] != 0)
			{
				if (result[row][i] == result[row][j])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_rowleft_valid(int result[][N], int clue, int row)
{
	int	box_count;
	int	visible_boxes;
	int	height;
	int	j;

	box_count = 0;
	j = 0;
	visible_boxes = 0;
	height = 0;
	while (j < N)
	{
		if (result[row][j] > height)
		{
			height = result[row][j];
			visible_boxes++;
		}
		if (result[row][j] != 0)
			box_count++;
		j++;
	}
	if (box_count == N && visible_boxes != clue)
		return (0);
	if (box_count < N && visible_boxes > clue)
		return (0);
	return (1);
}

int	ft_is_rowright_valid(int result[][N], int clue, int row)
{
	int	box_count;
	int	visible_boxes;
	int	height;
	int	j;

	box_count = 0;
	j = N - 1;
	visible_boxes = 0;
	height = 0;
	while (j >= 0)
	{
		if (result[row][j] > height)
		{
			height = result[row][j];
			visible_boxes++;
		}
		if (result[row][j] != 0)
			box_count++;
		j--;
	}
	if (box_count == N && visible_boxes != clue)
		return (0);
	if (box_count == N && visible_boxes > clue)
		return (0);
	return (1);
}

int	ft_rowleft_first_col_valid(int result[][N], int clue, int row, int col)
{
	if (result[row][col] > N - clue + 1 + col)
		return (0);
	return (1);
}

int	ft_rowright_first_col_valid(int result[][N], int clue, int row, int col)
{
	if (result[row][col] > N - clue + 1 + N - col)
		return (0);
	return (1);
}

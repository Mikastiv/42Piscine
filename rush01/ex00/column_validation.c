/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:19:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 16:19:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "column_validation.h"

int	ft_dup_in_col(int result[][N], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (result[j][col] != 0 && result[i][col] != 0)
			{
				if (result[i][col] == result[j][col])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_colup_valid(int result[][N], int clues, int col)
{
	int	box_count;
	int	visible_boxes;
	int	height;
	int	i;

	box_count = 0;
	i = 0;
	visible_boxes = 0;
	height = 0;
	while (i < N)
	{
		if (result[i][col] > height)
		{
			height = result[i][col];
			visible_boxes++;
		}
		if (result[i][col] != 0)
			box_count++;
		i++;
	}
	if (box_count == N && visible_boxes != clues)
		return (0);
	if (box_count < N && visible_boxes > clues)
		return (0);
	return (1);
}

int	ft_is_coldown_valid(int result[][N], int clues, int col)
{
	int	box_count;
	int	visible_boxes;
	int	height;
	int	i;

	box_count = 0;
	i = N - 1;
	visible_boxes = 0;
	height = 0;
	while (i >= 0)
	{
		if (result[i][col] > height)
		{
			height = result[i][col];
			visible_boxes++;
		}
		if (result[i][col] != 0)
			box_count++;
		i--;
	}
	if (box_count == N && visible_boxes != clues)
		return (0);
	if (box_count == N && visible_boxes > clues)
		return (0);
	return (1);
}

int	ft_colup_first_row_valid(int result[][N], int clue, int row, int col)
{
	if (result[row][col] > N - clue + 1 + row)
		return (0);
	return (1);
}

int	ft_coldown_first_row_valid(int result[][N], int clue, int row, int col)
{
	if (result[row][col] > N - clue + 1 + N - row)
		return (0);
	return (1);
}

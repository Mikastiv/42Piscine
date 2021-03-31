/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:05:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 16:07:37 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_solve.h"
#include "ft_range_check.h"

void	ft_solve_row(t_map *map, t_solution *sol, t_u32 row)
{
	t_u32	i;
	t_u32	col;
	t_u32	width;

	width = map->info->width;
	col = 0;
	i = 1;
	while (col < width)
	{
		if (valid_row(map, row, col, i) && valid_col(map, row, col, i))
		{
			ft_update_sol(sol, col, col + i, ft_2d_to_1d(row, col, width));
			i++;
		}
		else
		{
			col++;
			i = 1;
		}
	}
}

void	ft_put_solution(t_map *map, t_solution sol)
{
	t_u32	count;
	t_u32	i;
	t_u32	idx;

	count = 0;
	idx = sol.start_idx;
	while (count < sol.sq_size)
	{
		i = 0;
		while (i < sol.sq_size)
		{
			map->array[idx + (count * map->info->width) + i] = map->info->full;
			i++;
		}
		count++;
	}
}

t_solution	ft_solve(t_map *map)
{
	t_solution	sol;
	t_u32		row;
	t_u32		width;
	t_u32		height;

	height = map->info->height;
	width = map->info->width;
	sol = (t_solution){0, 0};
	row = 0;
	while (row < height)
	{
		if (height - row <= sol.sq_size)
			break ;
		ft_solve_row(map, &sol, row);
		row++;
	}
	return (sol);
}

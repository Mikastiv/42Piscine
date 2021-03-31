/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:13:37 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 13:59:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_range_check.h"

int	ft_is_hrange_valid(t_map *map, t_range range, t_u32 row)
{
	t_u32	width;

	width = map->info->width;
	if (range.max > width)
		return (0);
	while (range.min < range.max)
	{
		if (map->array[ft_2d_to_1d(row, range.min, width)] == map->info->wall)
			return (0);
		range.min++;
	}
	return (1);
}

int	ft_is_vrange_valid(t_map *map, t_range range, t_u32 col)
{
	t_u32	width;

	width = map->info->width;
	if (range.max > map->info->height)
		return (0);
	while (range.min < range.max)
	{
		if (map->array[ft_2d_to_1d(range.min, col, width)] == map->info->wall)
			return (0);
		range.min++;
	}
	return (1);
}

int	valid_row(t_map *map, t_u32 row, t_u32 col, t_u32 i)
{
	return (ft_is_hrange_valid(map, (t_range){col, col + i}, row + i - 1));
}

int	valid_col(t_map *map, t_u32 row, t_u32 col, t_u32 i)
{
	return (ft_is_vrange_valid(map, (t_range){row, row + i}, col + i - 1));
}

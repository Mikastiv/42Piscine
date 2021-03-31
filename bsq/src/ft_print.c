/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:35:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 17:36:54 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_map(t_map *map)
{
	t_u32	row;
	t_u32	col;

	row = 0;
	while (row < map->info->height)
	{
		col = 0;
		while (col < map->info->width)
		{
			write(1, &map->array[ft_2d_to_1d(row, col, map->info->width)], 1);
			col++;
		}
		ft_putstr("\n");
		row++;
	}
}

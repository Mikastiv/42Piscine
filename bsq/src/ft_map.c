/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:06:04 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 15:59:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_split.h"
#include "ft_file.h"
#include "ft_string.h"
#include "ft_stdint.h"
#include "ft_mem.h"
#include "ft_atoi.h"
#include <stdlib.h>

t_map_info	*ft_create_map_info(char *str)
{
	t_map_info	*map_info;
	int			strlen;

	strlen = ft_strlen(str);
	map_info = malloc(sizeof(t_map_info));
	map_info->full = *(str + --strlen);
	map_info->wall = *(str + --strlen);
	map_info->empty = *(str + --strlen);
	map_info->height = ft_atoi(str);
	return (map_info);
}

t_u32	ft_2d_to_1d(t_u32 row, t_u32 col, t_u32 width)
{
	return (row * width + col);
}

void	ft_fill_map(char *dest, char **src)
{
	t_u32	i;
	t_u32	j;
	t_u32	len;

	i = 1;
	j = 0;
	while (src[i])
	{
		len = ft_strlen(src[i]);
		ft_memcpy(&dest[j], src[i], len);
		j += len;
		i++;
	}
}

t_map	*ft_create_map(char *content)
{
	char	**split;
	t_map	*rtn;

	rtn = malloc(sizeof(t_map));
	if (!content)
		return (NULL);
	split = ft_split(content, '\n');
	rtn->info = ft_create_map_info(split[0]);
	rtn->info->width = ft_strlen(split[1]);
	rtn->array = malloc(sizeof(char) * rtn->info->height * rtn->info->width);
	ft_fill_map(rtn->array, split);
	return (rtn);
}

void	ft_free_map(t_map *map)
{
	free(map->info);
	free(map->array);
	free(map);
}

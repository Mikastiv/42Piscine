/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:53:40 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 15:57:45 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "ft_stdint.h"

typedef struct s_map_info
{
	t_u32	height;
	t_u32	width;
	char	empty;
	char	wall;
	char	full;
}	t_map_info;

typedef struct s_map
{
	t_map_info	*info;
	char		*array;
}	t_map;

t_map_info	ft_map_info(char *str);
void		ft_fill_map(char *dest, char **src);
t_map		*ft_create_map(char *content);
void		ft_free_map(t_map *map);
t_u32		ft_2d_to_1d(t_u32 row, t_u32 col, t_u32 width);

#endif

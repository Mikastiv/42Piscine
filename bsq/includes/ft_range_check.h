/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_check.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:42:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 13:40:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANGE_CHECK_H
# define FT_RANGE_CHECK_H

# include "ft_stdint.h"
# include "ft_map.h"

typedef struct s_range
{
	t_u32	min;
	t_u32	max;
}	t_range;

int	ft_is_vrange_valid(t_map *map, t_range range, t_u32 col);
int	ft_is_hrange_valid(t_map *map, t_range range, t_u32 row);
int	valid_row(t_map *map, t_u32 row, t_u32 col, t_u32 i);
int	valid_col(t_map *map, t_u32 row, t_u32 col, t_u32 i);

#endif

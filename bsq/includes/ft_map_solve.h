/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_solve.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:03:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 16:06:48 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_SOLVE_H
# define FT_MAP_SOLVE_H

# include "ft_map.h"
# include "ft_solution.h"

t_solution	ft_solve(t_map *map);
void		ft_put_solution(t_map *map, t_solution sol);

#endif

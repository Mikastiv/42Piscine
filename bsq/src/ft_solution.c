/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:46:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 14:05:33 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solution.h"

int	ft_update_sol(t_solution *sol, t_u32 min, t_u32 max, t_u32 index)
{
	if (max - min > sol->sq_size)
	{
		sol->sq_size = max - min;
		sol->start_idx = index;
		return (1);
	}
	return (0);
}

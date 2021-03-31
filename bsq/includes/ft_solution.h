/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:44:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 14:05:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLUTION_H
# define FT_SOLUTION_H

# include "ft_stdint.h"

typedef struct s_solution
{
	t_u32	sq_size;
	t_u32	start_idx;
}	t_solution;

int	ft_update_sol(t_solution *sol, t_u32 min, t_u32 max, t_u32 index);

#endif

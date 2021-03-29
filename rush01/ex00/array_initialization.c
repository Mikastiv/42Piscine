/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:06:08 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 14:14:02 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_initialization.h"

void	ft_parse_input(int viewers[][N], char *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < N)
		{
			viewers[i][j] = *input - '0';
			input += 2;
			j++;
		}
		i++;
	}
}

void	ft_init_result_array(int array[][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
}

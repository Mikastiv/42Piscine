/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:45:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 14:07:23 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_valid_num(char c)
{
	if (c >= '1' && c < '1' + N)
		return (1);
	else
		return (0);
}

int	ft_input_is_valid(char *input)
{
	int	count;
	int	prev_is_num;

	prev_is_num = 0;
	count = 0;
	while (*input != '\0' && count != 4 * N)
	{
		if (!prev_is_num && ft_is_valid_num(*input))
			count++;
		else if (prev_is_num && ft_is_space(*input))
		{
		}
		else
			return (0);
		prev_is_num = !prev_is_num;
		input++;
	}
	if (count == 4 * N && *input == '\0')
		return (1);
	return (0);
}

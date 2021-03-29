/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:59:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 19:29:03 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input_validation.h"
#include "ft_string.h"
#include "ft_atoi.h"

int	ft_is_input_valid(char *input)
{
	int	sign;

	sign = 1;
	if (ft_strlen(input) == 0)
		return (0);
	while (*input == '+' || *input == '-')
	{
		if (*input == '-')
			sign *= -1;
		input++;
	}
	if (sign < 0 && ft_atoi(input) != 0)
		return (0);
	while (*input >= '0' && *input <= '9')
		input++;
	return (*input == '\0');
}

void	ft_add_zeroes(char *num)
{
	unsigned int	len;

	len = ft_strlen(num);
	if (len == 2)
	{
		num[2] = num[1];
		num[1] = num[0];
		num[0] = '0';
	}
	if (len == 1)
	{
		num[2] = num[0];
		num[0] = '0';
		num[1] = '0';
	}
	num[3] = '\0';
}

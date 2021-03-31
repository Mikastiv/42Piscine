/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:45:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 15:46:29 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"
#include "ft_string.h"

int	ft_atoi(char *str)
{
	int	rtn;
	int	len;

	rtn = 0;
	len = ft_strlen(str);
	while (*str >= '0' && *str <= '9' && len >= 4)
	{
		rtn = (rtn * 10) + (*str - '0');
		len--;
		str++;
	}
	return (rtn);
}

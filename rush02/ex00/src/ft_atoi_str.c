/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:11:24 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/28 18:49:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi_str.h"
#include "ft_string.h"
#include <stdlib.h>

int	ft_count_numbers(char *str)
{
	int	count;

	count = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_ltrim_zeroes(char *str)
{
	char			*start;
	unsigned int	len;

	start = str;
	len = ft_strlen(str);
	while (*str == '0')
		str++;
	if (start != str && len > 1)
	{
		if (*str == '\0')
			ft_strcpy(start, str - 1);
		else
			ft_strcpy(start, str);
	}
	return (start);
}

char	*ft_ltrim_signs(char *str)
{
	char			*start;

	start = str;
	while (*str == '-' || *str == '+')
		str++;
	if (start != str)
		ft_strcpy(start, str);
	return (start);
}

char	*ft_atoi_str(char *str)
{
	char	*start;
	char	*ret;
	int		count;

	start = ft_ltrim(str, 0);
	count = ft_count_numbers(start);
	if (*start == '+')
		start++;
	ret = (char *)malloc(sizeof(char) * (count + 2));
	if (count == 0)
		return (ft_strncpy(ret, "0", 2));
	if (*start == '-')
		count++;
	ft_strncpy(ret, start, count);
	ret[count] = '\0';
	ft_ltrim_zeroes(ret);
	return (ret);
}

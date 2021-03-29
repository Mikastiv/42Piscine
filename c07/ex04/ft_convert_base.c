/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:40:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/23 10:57:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_is_base_valid(char *base);
char			*ft_itoa_base(int nbr, char *base);

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strchar(char *str, char to_find)
{
	while (*str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	return (0);
}

unsigned int	ft_char_base_value(char *base, char c)
{
	long			char_addr_value;

	char_addr_value = (long)ft_strchar(base, c);
	return ((unsigned int)(char_addr_value - (long)base));
}

int	ft_atoi_base(char *str, char *base)
{
	int	ret;
	int	sign;
	int	base_len;

	sign = 1;
	ret = 0;
	base_len = ft_strlen(base);
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_strchar(base, *str))
	{
		ret = (ret * base_len) + ft_char_base_value(base, *str);
		str++;
	}
	return (ret * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_value;
	char	*ret;

	if (!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return (NULL);
	nbr_value = ft_atoi_base(nbr, base_from);
	ret = ft_itoa_base(nbr_value, base_to);
	return (ret);
}

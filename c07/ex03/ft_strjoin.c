/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:07:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/22 16:02:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

unsigned int	ft_strlen_sum(char **strs, int size, char *sep)
{
	int				i;
	unsigned int	len_sum;
	unsigned int	sep_len;

	sep_len = ft_strlen(sep);
	len_sum = 0;
	i = 0;
	while (i < size)
	{
		len_sum += ft_strlen(strs[i]);
		len_sum += sep_len;
		i++;
	}
	len_sum -= sep_len;
	return (len_sum);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (ret);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	len_sum;
	int				i;
	char			*ret;

	if (size < 0)
		return (NULL);
	if (size == 0)
	{
		ret = malloc(1);
		*ret = 0;
		return (ret);
	}
	len_sum = ft_strlen_sum(strs, size, sep);
	ret = malloc((len_sum + 1) * sizeof(char));
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(ret, strs[i]);
		ft_strcat(ret, sep);
		i++;
	}
	return (ft_strcat(ret, strs[i]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:39:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 14:42:15 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*ret;
	unsigned int	i;

	ret = dest;
	i = 0;
	while (i < n && *src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}
	return (ret);
}

char	*ft_ltrim(char *str, int only_spaces)
{
	char	*start;

	start = str;
	if (only_spaces)
		while (*str == ' ')
			str++;
	else
		while ((*str >= '\t' && *str <= '\r') || *str == ' ')
			str++;
	if (start != str)
		ft_strcpy(start, str);
	return (start);
}

char	*ft_rtrim(char *str, int only_spaces)
{
	char	*start;

	start = str;
	while (*str)
		str++;
	str--;
	if (only_spaces)
		while (*str == ' ' && str > start)
			str--;
	else
		while (((*str >= '\t' && *str <= '\r') || *str == ' ') && str > start)
			str--;
	if (start < str)
		*(str + 1) = '\0';
	if (start == str)
		*start = '\0';
	return (start);
}

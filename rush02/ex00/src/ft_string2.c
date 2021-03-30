/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:24:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 17:28:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string2.h"
#include "ft_string.h"
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*ret;

	ret = src;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}

char	*ft_substr(char *str, unsigned int len)
{
	char			*ret;
	unsigned int	i;

	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_append_word(char *dest, char *word)
{
	ft_strcat(dest, word);
	ft_strcat(dest, " ");
}

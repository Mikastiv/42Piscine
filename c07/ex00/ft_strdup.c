/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:52:32 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/22 14:03:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

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

char	*ft_strdup(char *src)
{
	unsigned int	size;
	char			*str_dup;
	unsigned int	i;

	size = ft_strlen(src) + 1;
	str_dup = malloc(size * sizeof(char));
	if (!str_dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (*src)
	{
		str_dup[i] = *src;
		src++;
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

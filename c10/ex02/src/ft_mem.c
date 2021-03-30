/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:14:55 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 11:16:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	ft_memcpy(char *dest, char *src, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		dest[i] = src[i];
		i++;
	}
}

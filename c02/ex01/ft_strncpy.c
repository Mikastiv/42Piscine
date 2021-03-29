/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:01:57 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/15 15:15:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*ret;
	unsigned int	i;

	ret = dest;
	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < n)
	{
		while (i < n)
		{
			*dest = '\0';
			dest++;
			i++;
		}
	}
	return (ret);
}

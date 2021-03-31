/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:57:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 20:13:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str != *to_find)
		{
			str++;
			continue ;
		}
		i = 0;
		while (1)
		{
			if (to_find[i] == '\0')
				return (str);
			if (str[i] != to_find[i])
				break ;
			i++;
		}	
		str++;
	}
	return (0);
}

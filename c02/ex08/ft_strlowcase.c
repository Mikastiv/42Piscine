/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:23:17 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/14 15:27:04 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

char	*ft_strlowcase(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		*str = ft_to_lowercase(*str);
		str++;
	}
	return (ret);
}

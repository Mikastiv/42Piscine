/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:01:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/14 15:15:17 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

char	*ft_strupcase(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		*str = ft_to_uppercase(*str);
		str++;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:30:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/15 18:51:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

char	ft_to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

int	ft_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_char_is_alphanumeric(char c)
{
	if (ft_char_is_alpha(c) || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;
	char	*word_start;

	ret = str;
	while (*str)
	{
		word_start = str;
		while (ft_char_is_alphanumeric(*str))
		{
			*str = ft_to_lowercase(*str);
			str++;
		}
		*word_start = ft_to_uppercase(*word_start);
		str++;
	}
	return (ret);
}

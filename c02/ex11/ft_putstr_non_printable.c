/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:16:53 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/15 09:44:14 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_lsb_to_hex(char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[c & 0xF]);
}

void	ft_putchar_in_hex(char c)
{
	ft_putchar('\\');
	ft_putchar(ft_lsb_to_hex(c >> 4));
	ft_putchar(ft_lsb_to_hex(c & 0xF));
}

int	ft_char_is_non_printable(char c)
{
	if (c < ' ' || c > '~')
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_char_is_non_printable(*str))
			ft_putchar_in_hex(*str);
		else
			ft_putchar(*str);
		str++;
	}
}

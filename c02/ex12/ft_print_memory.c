/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:57:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/15 15:24:45 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BYTES_PER_LINE 16

// Converts to hex or test if char is not printable
char	to_hex_or_is_notp(char c, int to_hex)
{
	char	*hex;

	if (to_hex)
	{
		hex = "0123456789abcdef";
		return (hex[c & 0xF]);
	}
	else
	{
		if (c < ' ' || c > '~')
			return (1);
		else
			return (0);
	}
}

// Prints address or puts a char to stdout
void	paddr_or_pchar(void *addr, char c, int putchar)
{
	long			addr_l;
	char			hex;
	unsigned int	i;

	if (putchar)
		write(1, &c, 1);
	else
	{
		addr_l = (long)addr;
		i = 0;
		while (i < 16)
		{
			hex = to_hex_or_is_notp((addr_l & 0xF000000000000000) >> 60, 1);
			paddr_or_pchar(addr, hex, 1);
			addr_l <<= 4;
			i++;
		}
		paddr_or_pchar(addr, ':', 1);
		paddr_or_pchar(addr, ' ', 1);
	}
}

void	ft_print_memory_hex_bytes(void *addr, unsigned int size)
{
	char			c;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		c = *((char *)addr + i);
		paddr_or_pchar(addr, to_hex_or_is_notp(c >> 4, 1), 1);
		paddr_or_pchar(addr, to_hex_or_is_notp(c & 0xF, 1), 1);
		if (i % 2 != 0)
			paddr_or_pchar(addr, ' ', 1);
		i++;
	}
	if (size < BYTES_PER_LINE)
	{
		i = 0;
		while (i < BYTES_PER_LINE - size)
		{
			paddr_or_pchar(addr, ' ', 1);
			i++;
		}
	}
}

void	ft_print_printable_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				last_char_is_space;

	last_char_is_space = 0;
	i = 0;
	while (i < size)
	{
		if (to_hex_or_is_notp(*((char *)addr + i), 0))
			paddr_or_pchar(addr, '.', 1);
		else
		{
			if (last_char_is_space && *((char *)addr + i) == ' ')
			{
				i++;
				continue ;
			}
			paddr_or_pchar(addr, *((char *)addr + i), 1);
			if (*((char *)addr + i) == ' ')
				last_char_is_space = 1;
			else
				last_char_is_space = 0;
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i > size - BYTES_PER_LINE)
		{
			paddr_or_pchar(addr + i, ' ', 0);
			ft_print_memory_hex_bytes(addr + i, size - i);
			ft_print_printable_memory(addr + i, size - i);
			paddr_or_pchar(addr, '\n', 1);
			break ;
		}
		paddr_or_pchar(addr + i, ' ', 0);
		ft_print_memory_hex_bytes(addr + i, BYTES_PER_LINE);
		ft_print_printable_memory(addr + i, BYTES_PER_LINE);
		paddr_or_pchar(addr, '\n', 1);
		i += BYTES_PER_LINE;
	}
	return (addr);
}

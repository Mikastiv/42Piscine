/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:09:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/18 14:45:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strchar(char *str, char to_find)
{
	while (*str)
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	return (0);
}

void	ft_putnbr_recursive(int nbr, char *base, int base_len)
{
	if (nbr < 0 && nbr / base_len == 0)
		write(1, "-", 1);
	if (nbr / base_len != 0)
		ft_putnbr_recursive(nbr / base_len, base, base_len);
	if (nbr % base_len < 0)
		write(1, &base[(nbr % base_len) * -1], 1);
	else
		write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	int				base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return ;
	if (ft_strchar(base, '+') || ft_strchar(base, '-'))
		return ;
	i = 0;
	while (*(base + i))
	{
		if (ft_strchar(base + i + 1, *(base + i)))
			return ;
		i++;
	}
	ft_putnbr_recursive(nbr, base, base_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:38:50 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/24 17:28:48 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	int	index;

	if (nbr < 0 && nbr / 10 == 0)
		ft_putstr("-");
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	if (nbr % 10 < 0)
	{
		index = (nbr % 10) * -1;
		write(1, &"0123456789" [index], 1);
	}
	else
		write(1, &"0123456789" [nbr % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}

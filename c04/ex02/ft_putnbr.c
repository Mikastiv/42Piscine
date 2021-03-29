/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:32:03 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/17 10:35:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb / 10 == 0)
		ft_putchar('-');
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	if (nb % 10 < 0)
		ft_putchar((nb % 10) * -1 + '0');
	else
		ft_putchar((nb % 10) + '0');
}

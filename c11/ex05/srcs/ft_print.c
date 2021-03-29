/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:52 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/26 13:39:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0 && nbr / 10 == 0)
		ft_putchar('-');
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	if (nbr % 10 < 0)
		ft_putchar((nbr % 10) * -1 + '0');
	else
		ft_putchar((nbr % 10) + '0');
}

void	ft_print_error_msg(char operator)
{
	if (operator == '/')
		ft_putstr("Stop : division by zero\n");
	if (operator == '%')
		ft_putstr("Stop : modulo by zero\n");
}

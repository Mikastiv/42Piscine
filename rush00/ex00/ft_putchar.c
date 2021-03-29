/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:57:31 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/13 10:57:48 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_line(int width, char c1, char c2, char c3)
{
	int	i;

	ft_putchar(c1);
	i = 1;
	while (i < width - 1)
	{
		ft_putchar(c2);
		i++;
	}
	if (width > 1)
		ft_putchar(c3);
	ft_putchar('\n');
}

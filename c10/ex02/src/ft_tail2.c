/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:59:52 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 12:13:01 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail2.h"

void	ft_print_tail(char *buf, ssize_t len, ssize_t count)
{
	ssize_t	start;

	if (len <= count)
	{
		start = 0;
		count = len;
	}
	else
		start = len - count;
	write(1, &buf[start], count);
}

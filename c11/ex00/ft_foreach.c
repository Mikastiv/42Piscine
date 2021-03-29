/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:21:24 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/26 10:25:22 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	if (length < 1)
		return ;
	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

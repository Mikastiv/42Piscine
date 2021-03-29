/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:57:16 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/19 10:12:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isqrt(int nb)
{
	int	x;
	int	y;

	if (nb < 1)
		return (0);
	x = nb;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}

int	ft_is_prime(int nb)
{
	int	sqrt;
	int	divisor;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	sqrt = ft_isqrt(nb);
	divisor = 2;
	while (divisor <= sqrt)
	{
		if (nb % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	current_nb;

	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	current_nb = nb;
	while (!ft_is_prime(current_nb))
		current_nb++;
	return (current_nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:40:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/23 10:56:56 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);
char			*ft_strchar(char *str, char to_find);

int	ft_is_base_valid(char *base)
{
	unsigned int	base_len;
	unsigned int	i;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (ft_strchar(&base[i + 1], base[i]))
			return (0);
		i++;
	}
	return (1);
}

unsigned int	ft_number_count(int nbr, unsigned int base_len)
{
	unsigned int	count;

	count = 0;
	while (nbr / base_len != 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count + 1);
}

void	ft_itoa_recursive(char *out, int nbr, char *base, int pos)
{
	unsigned int	index;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr / base_len != 0)
		ft_itoa_recursive(out, nbr / base_len, base, pos - 1);
	if (nbr % base_len < 0)
	{
		index = (nbr % base_len) * -1;
		out[pos] = base[index];
	}
	else
		out[pos] = base[nbr % base_len];
}

char	*ft_alloc_space(int nbr, unsigned int num_count)
{
	char	*ret;

	if (nbr < 0)
	{
		ret = malloc(num_count + 2);
		ret[num_count + 1] = '\0';
	}
	else
	{
		ret = malloc(num_count + 1);
		ret[num_count] = '\0';
	}
	return (ret);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char			*ret;
	unsigned int	num_count;
	unsigned long	n_positive;

	if (nbr < 0)
		n_positive = (long)(nbr * -1);
	else
		n_positive = nbr;
	num_count = ft_number_count(n_positive, ft_strlen(base));
	ret = ft_alloc_space(nbr, num_count);
	if (nbr < 0)
	{
		ret[0] = '-';
		ft_itoa_recursive(ret, n_positive, base, num_count);
	}
	else
		ft_itoa_recursive(ret, n_positive, base, num_count - 1);
	return (ret);
}

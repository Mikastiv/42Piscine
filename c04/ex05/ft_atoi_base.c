/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:52:25 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/17 16:48:58 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_base_is_valid(char *base)
{
	unsigned int	base_len;
	char			c;
	unsigned int	i;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (*(base + i))
	{
		c = *(base + i);
		if ((c >= 9 && c <= 13) || c == ' ' || c == '+' || c == '-')
			return (0);
		if (ft_strchar(base + i + 1, *(base + i)))
			return (0);
		i++;
	}
	return (1);
}

int	ft_char_base_value(char *base, char c)
{
	long	c_addr_value;
	int		ret;

	c_addr_value = (long)ft_strchar(base, c);
	ret = (int)(c_addr_value - (long)base);
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int				sign;
	int				ret;

	sign = 1;
	ret = 0;
	if (!ft_base_is_valid(base))
		return (0);
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		else
			sign *= 1;
		str++;
	}
	while (*str && ft_strchar(base, *str))
	{
		ret = (ret * ft_strlen(base)) + ft_char_base_value(base, *str);
		str++;
	}
	return (ret * sign);
}

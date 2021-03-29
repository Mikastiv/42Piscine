/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:45:05 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/17 11:06:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	ft_sign_value(char sign)
{
	if (sign == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	while (*str && ft_is_whitespace(*str))
		str++;
	while (*str && ft_is_sign(*str))
	{
		sign *= ft_sign_value(*str);
		str++;
	}
	while (*str && ft_is_numeric(*str))
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (ret * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:19:23 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 19:06:23 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_convert.h"
#include "ft_dict_convert2.h"
#include "ft_dict2.h"
#include "ft_string.h"
#include "ft_string2.h"
#include "ft_atoi_str.h"
#include <stdlib.h>

#define RESULT_MAX_SIZE 8192

void	ft_set_to_pow_of_10(char *mem, char first_num, unsigned int pow)
{
	unsigned int	i;

	i = 1;
	mem[0] = first_num;
	while (i <= pow)
		mem[i++] = '0';
	mem[i] = '\0';
}

void	ft_prepare_3num(char *dest, char *num, int size)
{
	if (size == 0)
	{
		dest[0] = num[0];
		dest[1] = num[1];
		dest[2] = num[2];
	}
	if (size == 2)
	{
		dest[0] = '0';
		dest[1] = num[0];
		dest[2] = num[1];
	}
	if (size == 1)
	{
		dest[0] = '0';
		dest[1] = '0';
		dest[2] = num[0];
	}
	dest[3] = '\0';
}

char	*ft_to_closest_pow10(char *num)
{
	unsigned int	len;

	len = ft_strlen(num);
	if (len % 3 == 0)
		return (num + 2);
	if (len % 3 == 2)
		return (num + 1);
	return (num);
}

int	app_pow10(t_dict dict, char *dest, char *num, int show)
{
	t_entry			*entry;
	unsigned int	len;
	unsigned int	i;
	char			*buf;

	if (ft_strncmp(num, "000", 3) == 0 || !show)
		return (1);
	num = ft_to_closest_pow10(num);
	len = ft_strlen(num);
	buf = malloc(sizeof(char) * (len + 1));
	buf[0] = '1';
	i = 1;
	while (i < len)
		buf[i++] = '0';
	buf[i] = '\0';
	entry = ft_find_entry(dict, buf);
	if (entry)
		ft_append_word(dest, entry->value);
	else
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
}

char	*ft_convert_num(t_dict dict, char *num)
{
	unsigned int	len;
	char			*ret;
	char			buf[4];

	ret = malloc(sizeof(char) * RESULT_MAX_SIZE);
	*ret = '\0';
	len = ft_strlen(num);
	while (len / 3 >= 1)
	{
		ft_prepare_3num(buf, num, len % 3);
		if (!conv_3num(dict, ret, buf) || !app_pow10(dict, ret, num, len > 3))
		{
			free(ret);
			return (NULL);
		}
		if (len % 3 == 0)
			num += 3;
		else
			num += len % 3;
		len = ft_strlen(num);
	}
	len = ft_strlen(ret);
	if (ret[len - 1] == ' ')
		ret[len - 1] = '\0';
	return (ret);
}

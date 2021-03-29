/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_convert2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:26:48 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 17:43:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict_convert2.h"
#include "ft_dict_convert.h"
#include "ft_dict2.h"
#include "ft_string2.h"
#include "ft_string.h"

int	ft_append_hundreds(t_dict dict, char *dest, char *num)
{
	t_entry	*entry;
	char	buf[4];

	if (num[0] >= '1')
	{
		ft_set_to_pow_of_10(buf, *num, 0);
		entry = ft_find_entry(dict, buf);
		if (entry)
			ft_append_word(dest, entry->value);
		else
			return (0);
		num[0] = '1';
	}
	if (num[0] == '1')
	{
		ft_set_to_pow_of_10(buf, '1', 2);
		entry = ft_find_entry(dict, buf);
		if (entry)
			ft_append_word(dest, entry->value);
		else
			return (0);
	}
	return (1);
}

int	ft_append_under_twenty(t_dict dict, char *dest, char *num)
{
	t_entry	*entry;
	char	buf[3];

	buf[0] = num[1];
	buf[1] = num[2];
	buf[2] = '\0';
	entry = ft_find_entry(dict, buf);
	if (entry)
	{
		ft_append_word(dest, entry->value);
		return (1);
	}
	return (0);
}

int	ft_append_tens_and_units(t_dict dict, char *dest, char *num)
{
	t_entry	*entry;
	char	buf[3];

	if (ft_append_under_twenty(dict, dest, num))
		return (1);
	if (num[1] >= '1')
	{
		ft_set_to_pow_of_10(buf, num[1], 1);
		entry = ft_find_entry(dict, buf);
		if (entry)
			ft_append_word(dest, entry->value);
		else
			return (0);
		num[1] = '0';
	}
	if (num[2] > '0')
	{
		ft_set_to_pow_of_10(buf, num[2], 0);
		entry = ft_find_entry(dict, buf);
		if (entry)
			ft_append_word(dest, entry->value);
		else
			return (0);
	}
	return (1);
}

int	conv_3num(t_dict dict, char *dest, char *num)
{
	if (!ft_append_hundreds(dict, dest, num))
		return (0);
	if (!ft_append_tens_and_units(dict, dest, num))
		return (0);
	return (1);
}

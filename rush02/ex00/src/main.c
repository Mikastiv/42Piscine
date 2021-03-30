/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:50:30 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/29 10:33:39 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include "ft_dict2.h"
#include "ft_string.h"
#include "ft_string2.h"
#include "ft_print.h"
#include "ft_atoi_str.h"
#include "ft_dict_convert.h"
#include "ft_dict_convert2.h"
#include "ft_input_validation.h"
#include <stdlib.h>

int	ft_parse_args(t_dict *dict, char **input, int argc, char **argv)
{
	if (argc == 2)
	{
		*input = ft_substr(argv[1], ft_strlen(argv[1]));
		*dict = ft_load_dictionary("numbers.dict");
		return (1);
	}
	if (argc == 3)
	{
		*input = ft_substr(argv[2], ft_strlen(argv[2]));
		*dict = ft_load_dictionary(argv[1]);
		return (1);
	}
	return (0);
}

int	ft_print_zero(t_dict dict)
{
	t_entry	*entry;

	entry = ft_find_entry(dict, "0");
	if (entry)
	{
		ft_putstr(entry->value);
		return (1);
	}
	else
		return (0);
}

int	ft_main_delegate(t_dict dict, char *input)
{
	unsigned int	len;
	char			buf[4];
	char			*res;

	ft_ltrim_signs(input);
	ft_ltrim_zeroes(input);
	len = ft_strlen(input);
	if (len == 1 && *input == '0')
		return (ft_print_zero(dict));
	if (len < 3)
	{
		ft_strncpy(buf, input, 4);
		ft_add_zeroes(buf);
		res = ft_convert_num(dict, buf);
	}
	else
		res = ft_convert_num(dict, input);
	if (res)
	{
		ft_putstr(res);
		free(res);
		return (1);
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_dict	dict;
	char	*input;

	if (!ft_parse_args(&dict, &input, argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!dict)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	if (!ft_is_input_valid(input))
	{
		ft_putstr("Error\n");
		ft_free_dict(dict);
		return (0);
	}
	if (!ft_main_delegate(dict, input))
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_putstr("\n");
	ft_free_dict(dict);
}

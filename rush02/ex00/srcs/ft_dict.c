/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:52:43 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/28 15:48:23 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"
#include "ft_dict2.h"
#include "ft_file.h"
#include "ft_split.h"
#include "ft_string.h"
#include <stdlib.h>

int	ft_is_line_valid(char *line)
{
	while (*line && (*line >= ' ' && *line <= '~') && *line != ':')
		line++;
	if (*line != ':')
		return (0);
	line++;
	while (*line && (*line >= ' ' && *line <= '~'))
		line++;
	return (*line == '\0');
}

int	ft_is_dict_valid(char **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (!ft_is_line_valid(dict[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_replace_newlines(char *str)
{
	int	in_number;

	in_number = 1;
	while (*str)
	{
		if (in_number && *str == '\n')
			*str = ' ';
		if (in_number && *str == ':')
			in_number = 0;
		if (!in_number && *str == '\n')
			in_number = 1;
		str++;
	}
}

t_dict	ft_load_dictionary(char *filename)
{
	char	*file_content;
	char	**dict_lines;
	t_dict	dict;

	file_content = ft_read_file(filename);
	if (!file_content)
		return (NULL);
	ft_replace_newlines(file_content);
	dict_lines = ft_split(file_content, '\n');
	free(file_content);
	if (!dict_lines)
		return (NULL);
	if (!ft_is_dict_valid(dict_lines))
	{
		ft_free_str_array(dict_lines);
		return (NULL);
	}
	if (!ft_is_dict_valid(dict_lines))
	{
		ft_free_str_array(dict_lines);
		return (NULL);
	}
	dict = ft_create_dict(dict_lines);
	ft_free_str_array(dict_lines);
	return (dict);
}

void	ft_free_dict(t_dict dict)
{
	unsigned int	i;

	i = 0;
	while (dict[i])
	{
		free(dict[i]->value);
		free(dict[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:26:43 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 16:52:58 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid_map.h"
#include "ft_map.h"
#include "ft_split.h"
#include "ft_string.h"
#include "ft_file.h"
#include "ft_atoi.h"

#include <stdio.h>

int	ft_lines_count(char **lines)
{
	int		count;
	int		i;

	count = ft_atoi(lines[0]);
	i = 0;
	while (lines[i + 1])
		i++;
	if (i == count)
		return (1);
	return (0);
}

int	ft_only_valid_char(char **lines)
{
	char	empty;
	char	obstacle;
	int		i;
	int		j;

	empty = lines[0][ft_strlen(lines[0]) - 3];
	obstacle = lines[0][ft_strlen(lines[0]) - 2];
	i = 1;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] != empty && lines[i][j] != obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_all_printable_char(char **lines)
{
	t_u32	i;
	t_u32	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!(lines[i][j] >= ' ' && lines[i][j] <= '~'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_legend_valid(char *legend)
{
	int		len;
	char	empty;
	char	full;
	char	wall;
	char	*ptr;

	len = ft_strlen(legend);
	if (len < 4)
		return (0);
	full = legend[len - 1];
	wall = legend[len - 2];
	empty = legend[len - 3];
	if (full == wall || full == empty)
		return (0);
	if (empty == wall || !ft_is_printable(&legend[len - 3]))
		return (0);
	ptr = legend;
	while (ptr < &legend[len - 3])
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (0);
		ptr++;
	}
	return (1);
}

int	ft_is_valid_map(char *map_str)
{
	char	**lines;
	int		i;
	int		len;

	lines = ft_split(map_str, '\n');
	if (!lines[0] || !lines[1])
		return (0);
	i = 2;
	len = ft_strlen(lines[1]);
	while (lines[i])
	{
		if (len != ft_strlen(lines[i]))
			return (0);
		i++;
	}
	if (!ft_all_printable_char(lines + 1))
		return (0);
	if (!ft_is_legend_valid(lines[0]))
		return (0);
	if (!ft_only_valid_char(lines) || !ft_lines_count(lines))
		return (0);
	i = 0;
	return (1);
}

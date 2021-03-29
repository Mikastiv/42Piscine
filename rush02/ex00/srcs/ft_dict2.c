/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:16:24 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 13:21:29 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict2.h"
#include "ft_dict.h"
#include "ft_atoi_str.h"
#include "ft_split.h"
#include "ft_string.h"
#include "ft_string2.h"
#include <stdlib.h>

unsigned int	ft_entry_count(char **array)
{
	unsigned int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

t_entry	*ft_create_entry(char *line)
{
	char	**split;
	t_entry	*entry;

	split = ft_split(line, ':');
	if (!split)
		return (NULL);
	entry = malloc(sizeof(t_entry));
	if (!entry)
	{
		ft_free_str_array(split);
		return (NULL);
	}
	ft_ltrim(split[1], 0);
	ft_rtrim(split[1], 0);
	entry->value = malloc(sizeof(char) * (ft_strlen(split[1] + 1)));
	if (!entry->value)
	{
		ft_free_str_array(split);
		free(entry);
		return (NULL);
	}
	ft_strcpy(entry->value, split[1]);
	entry->key = ft_atoi_str(split[0]);
	ft_free_str_array(split);
	return (entry);
}

t_dict	ft_create_dict(char **entries)
{
	unsigned int	i;
	t_dict			dict;
	unsigned int	count;

	count = ft_entry_count(entries);
	dict = malloc(sizeof(t_entry *) * (count + 1));
	if (!dict)
		return (NULL);
	i = 0;
	while (entries[i])
	{
		dict[i] = ft_create_entry(entries[i]);
		if (!dict[i])
		{
			ft_free_dict(dict);
			return (NULL);
		}
		i++;
	}
	dict[i] = NULL;
	return (dict);
}

t_entry	*ft_find_entry(t_dict dict, char *key)
{
	unsigned int	i;

	i = 0;
	while (dict[i])
	{
		if (ft_strcmp(dict[i]->key, key) == 0)
			return (dict[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:04:51 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 11:01:27 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include "ft_string.h"
#include <stdlib.h>

unsigned int	ft_count_words(char *str, char d)
{
	char			*w_start;
	unsigned int	count;
	int				in_word;

	in_word = 0;
	count = 0;
	w_start = str;
	while (*str)
	{
		if (in_word && *str == d)
			count++;
		if (*str == d)
			in_word = 0;
		else
			in_word = 1;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

char	*ft_create_word(char *start, unsigned int length, char d)
{
	char	*word;

	if (*start == d)
	{
		start++;
		length--;
	}
	word = malloc(sizeof(char) *(length + 1));
	ft_strncpy(word, start, length);
	word[length] = '\0';
	return (word);
}

unsigned long	ft_ptr_dist(char *addr1, char *addr2)
{
	return ((unsigned long)addr2 - (unsigned long)addr1);
}

char	**ft_split(char *str, char d)
{
	unsigned int	i;
	char			*w_start;
	char			**words;
	int				in_word;

	words = malloc(sizeof(char *) * (ft_count_words(str, d) + 1));
	w_start = str;
	in_word = 0;
	i = 0;
	while (*str)
	{
		if (in_word && *str == d)
			words[i++] = ft_create_word(w_start, ft_ptr_dist(w_start, str), d);
		if (*str == d)
			in_word = 0;
		else
			in_word = 1;
		if (!in_word)
			w_start = str;
		str++;
	}
	if (in_word)
		words[i++] = ft_create_word(w_start, ft_ptr_dist(w_start, str), d);
	words[i] = NULL;
	return (words);
}

void	ft_free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

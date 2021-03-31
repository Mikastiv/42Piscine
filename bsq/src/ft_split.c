/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:42:05 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 10:28:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include "ft_string.h"
#include <stdlib.h>

unsigned int	ft_count_words(char *str, char sep)
{
	unsigned int	count;
	int				in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (in_word && *str == sep)
			count++;
		if (*str == sep)
			in_word = 0;
		else
			in_word = 1;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

char	*ft_create_word(char *start, unsigned int len, char sep)
{
	char	*word;

	if (*start == sep)
	{
		start++;
		len--;
	}
	word = malloc(sizeof(char) * (len + 1));
	ft_strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

unsigned long	ft_ptr_d(char *addr1, char *addr2)
{
	return ((unsigned long)addr2 - (unsigned long)addr1);
}

char	**ft_split(char *str, char sep)
{
	unsigned int	i;
	char			*w_start;
	char			**words;
	int				in_word;

	words = malloc(sizeof(char *) * (ft_count_words(str, sep) + 1));
	w_start = str;
	in_word = 0;
	i = 0;
	while (*str)
	{
		if (in_word && *str == sep)
			words[i++] = ft_create_word(w_start, ft_ptr_d(w_start, str), sep);
		if (*str == sep)
			in_word = 0;
		else
			in_word = 1;
		if (!in_word)
			w_start = str;
		str++;
	}
	if (in_word)
		words[i++] = ft_create_word(w_start, ft_ptr_d(w_start, str), sep);
	words[i++] = NULL;
	return (words);
}

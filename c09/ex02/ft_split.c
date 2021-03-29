/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:26:07 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/25 17:54:58 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_count_words(char *str, char *charset)
{
	int		count;
	char	*w_start;
	int		in_word;

	count = 0;
	in_word = 0;
	w_start = str;
	while (*str)
	{
		if (in_word && ft_strchar(charset, *str))
			count++;
		if (ft_strchar(charset, *str))
			in_word = 0;
		else
			in_word = 1;
		if (!in_word)
			w_start = str;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

char	*ft_get_word(char *str, int len, char *charset)
{
	char	*word;
	int		i;

	if (ft_strchar(charset, *str))
	{
		str++;
		len--;
	}
	word = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	ft_pdist(char *start, char *end)
{
	return ((long)end - (long)start);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	char	*w_start;
	int		in_word;

	ret = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	w_start = str;
	in_word = 0;
	i = 0;
	while (*str)
	{
		if (in_word && ft_strchar(charset, *str))
			ret[i++] = ft_get_word(w_start, ft_pdist(w_start, str), charset);
		if (ft_strchar(charset, *str))
			in_word = 0;
		else
			in_word = 1;
		if (!in_word)
			w_start = str;
		str++;
	}
	if (in_word)
		ret[i++] = ft_get_word(w_start, ft_pdist(w_start, str), charset);
	ret[i] = NULL;
	return (ret);
}

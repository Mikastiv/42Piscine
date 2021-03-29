/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:20:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/24 10:11:37 by mleblanc         ###   ########.fr       */
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
	char	*w_end;

	count = 0;
	w_start = str;
	w_end = str;
	while (1)
	{
		if (ft_strchar(charset, *str))
			w_end = str;
		if ((long)w_end - (long)w_start >= 1)
			count++;
		if (!*str)
			break ;
		w_start = w_end;
		str++;
	}
	if ((long)str - (long)w_start > 1)
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
	char	*w_end;

	ret = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	w_start = str;
	w_end = str;
	i = 0;
	while (1)
	{
		if (ft_strchar(charset, *str))
			w_end = str;
		if (ft_pdist(w_start, w_end) >= 1)
			ret[i++] = ft_get_word(w_start, ft_pdist(w_start, w_end), charset);
		if (*str == '\0')
			break ;
		w_start = w_end;
		str++;
	}
	if (ft_pdist(w_start, str) > 1)
		ret[i++] = ft_get_word(w_start, ft_pdist(w_start, str), charset);
	ret[i] = NULL;
	return (ret);
}

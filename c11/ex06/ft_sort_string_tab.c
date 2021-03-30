/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:16:34 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/29 11:32:02 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min_idx;

	if (!tab || !tab[0])
		return ;
	i = 0;
	while (tab[i + 1])
	{
		min_idx = i;
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[min_idx], tab[j]) > 0)
				min_idx = j;
			j++;
		}
		ft_swap(&tab[min_idx], &tab[i]);
		i++;
	}
}

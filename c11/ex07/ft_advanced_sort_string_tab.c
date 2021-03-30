/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:36:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/29 18:36:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	unsigned int	i;
	unsigned int	size;
	int				swap;

	size = 0;
	while (tab[size])
		size++;
	i = 0;
	while (1)
	{
		i = 0;
		swap = 0;
		while (i < size - 1)
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swap = 1;
			}
			i++;
		}
		if (!swap)
			break ;
	}
}

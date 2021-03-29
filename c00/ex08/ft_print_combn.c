/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:28:04 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/12 11:38:21 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_N_COMB 252
#define MAX_N 9
#define N_OBJECTS 10

int	g_results[MAX_N_COMB][MAX_N];
int	g_results_index;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_find_comb(int *temp_buf, int start, int index, int sample_size)
{
	int	i;

	if (index == sample_size)
	{
		i = 0;
		while (i < sample_size)
		{
			g_results[g_results_index][i] = temp_buf[i];
			i++;
		}
		g_results_index++;
		return ;
	}
	i = start;
	while (i < N_OBJECTS)
	{
		temp_buf[index] = i;
		ft_find_comb(temp_buf, i + 1, index + 1, sample_size);
		i++;
	}
}

void	ft_init_n_comb_array(int *n_comb)
{
	n_comb[0] = 10;
	n_comb[1] = 45;
	n_comb[2] = 120;
	n_comb[3] = 210;
	n_comb[4] = 252;
	n_comb[5] = 210;
	n_comb[6] = 120;
	n_comb[7] = 45;
	n_comb[8] = 10;
}

void	ft_init_globals(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_N_COMB)
	{
		j = 0;
		while (j < MAX_N)
		{
			g_results[i][j] = 0;
			j++;
		}
		i++;
	}
	g_results_index = 0;
}

void	ft_print_combn(int n)
{
	int	comb_count[MAX_N];
	int	temp_buf[MAX_N];
	int	n_comb;
	int	i;
	int	j;

	if (n <= 0 || n >= 10)
		return ;
	ft_init_globals();
	ft_init_n_comb_array(comb_count);
	n_comb = comb_count[n - 1];
	ft_find_comb(temp_buf, 0, 0, n);
	i = 0;
	while (i < n_comb)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(g_results[i][j] + '0');
			j++;
		}
		if (i != n_comb - 1)
			write(1, ", ", 2);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:04:05 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/31 18:22:50 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid_map.h"
#include "ft_map.h"
#include "ft_print.h"
#include "ft_mem.h"
#include "ft_range_check.h"
#include "ft_solution.h"
#include "ft_file.h"
#include "ft_map_solve.h"
#include <unistd.h>
#include <stdlib.h>

#define MALLOC_SIZE 16384

void	ft_process_map(char *file_content, int b_newline)
{
	t_map		*map;
	t_solution	sol;

	if (!file_content || !ft_is_valid_map(file_content))
	{
		ft_putstr("map error\n");
		if (b_newline)
			ft_putstr("\n");
		return ;
	}
	map = ft_create_map(file_content);
	sol = ft_solve(map);
	if (sol.sq_size != 0)
		ft_put_solution(map, sol);
	ft_print_map(map);
	if (b_newline)
		ft_putstr("\n");
	ft_free_map(map);
}

void	ft_solve_stdin(void)
{
	char	*input;
	char	*tmp;
	t_u32	malloc_count;
	ssize_t	bytes_read;
	ssize_t	count;

	malloc_count = 1;
	input = malloc(sizeof(char) * (MALLOC_SIZE + 1));
	count = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (count >= (MALLOC_SIZE + 1) * malloc_count)
		{
			tmp = malloc(sizeof(char) * (MALLOC_SIZE * malloc_count + 1));
			ft_memcpy(tmp, input, count);
			free(input);
			malloc_count++;
			input = tmp;
		}
		bytes_read = read(0, &input[count], 1);
		count += bytes_read;
	}
	input[count] = '\0';
	ft_process_map(input, 0);
}

int	main(int argc, char **argv)
{
	char	*file_content;
	int		i;

	if (argc <= 1)
	{
		ft_solve_stdin();
		return (0);
	}
	i = 1;
	while (i < argc - 1)
	{
		file_content = ft_read_file(argv[i]);
		ft_process_map(file_content, 1);
		free(file_content);
		i++;
	}
	file_content = ft_read_file(argv[i]);
	ft_process_map(file_content, 0);
	free(file_content);
}

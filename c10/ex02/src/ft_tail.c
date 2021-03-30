/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:26:36 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 12:12:52 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include "ft_tail2.h"
#include "ft_file.h"
#include "ft_string.h"
#include "ft_mem.h"
#include <libgen.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define NL_AND_NAME 2
#define NAME_ONLY 1

#define MALLOC_SIZE 8192

void	ft_display_fname(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	write(STDOUT, "==> ", 4);
	write(STDOUT, filename, len);
	write(STDOUT, " <==\n", 5);
}

void	ft_display_error(char *exec_name, char *file, int opt)
{
	if (errno == 0)
		return ;
	if (errno == EISDIR)
	{
		if (opt == 0)
			return ;
		if (opt == NL_AND_NAME)
			write(1, "\n", 1);
		ft_display_fname(file);
		return ;
	}
	ft_strwrite(basename(exec_name), STDERR);
	ft_strwrite(": ", STDERR);
	ft_strwrite(file, STDERR);
	ft_strwrite(": ", STDERR);
	ft_strwrite(strerror(errno), STDERR);
	ft_strwrite("\n", STDERR);
	errno = 0;
}

void	ft_display_tail(char *exec_name, char *file, ssize_t count, int opt)
{
	ssize_t	filesize;
	char	*buf;
	int		start;

	filesize = ft_filesize(file);
	buf = ft_read_file(file, filesize);
	if (filesize == -1)
	{
		ft_display_error(exec_name, file, opt);
		return ;
	}
	if (filesize <= count)
	{
		start = 0;
		count = filesize;
	}
	else
		start = filesize - count;
	if (opt == NL_AND_NAME)
		write(1, "\n", 1);
	if (opt == NAME_ONLY || opt == NL_AND_NAME)
		ft_display_fname(file);
	write(STDOUT, &buf[start], count);
	free(buf);
}

void	ft_tail(int argc, char **argv, ssize_t count)
{
	int	i;

	if (argc == 4)
		ft_display_tail(argv[0], argv[3], count, 0);
	else
	{
		ft_display_tail(argv[0], argv[3], count, NAME_ONLY);
		i = 4;
		while (i < argc)
		{
			ft_display_tail(argv[0], argv[i], count, NL_AND_NAME);
			i++;
		}
	}
}

void	ft_tail_stdin(ssize_t c)
{
	ssize_t	bytes_read;
	ssize_t	b_count;
	char	*buf;
	char	*tmp;
	ssize_t	malloc_count;

	buf = malloc(sizeof(char) * MALLOC_SIZE);
	malloc_count = 1;
	b_count = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (b_count >= (MALLOC_SIZE * malloc_count))
		{
			malloc_count++;
			tmp = malloc(sizeof(char) * (MALLOC_SIZE * malloc_count));
			ft_memcpy(tmp, buf, (MALLOC_SIZE * (malloc_count - 1)));
			free(buf);
			buf = tmp;
		}
		bytes_read = read(0, &buf[b_count], 1);
		b_count += bytes_read;
	}
	ft_print_tail(buf, b_count, c);
	free(buf);
}

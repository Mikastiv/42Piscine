/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:30:39 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 10:01:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include "ft_string.h"
#include <libgen.h>
#include <sys/errno.h>
#include <string.h>
#include <fcntl.h>

#define BUF_SIZE 28672
#define STDIN 0
#define STDOUT 1
#define STDERR 2

void	ft_display_error(char *exec_name, char *file)
{
	if (errno == 0)
		return ;
	ft_strwrite(basename(exec_name), STDERR);
	ft_strwrite(": ", STDERR);
	ft_strwrite(file, STDERR);
	ft_strwrite(": ", STDERR);
	ft_strwrite(strerror(errno), STDERR);
	ft_strwrite("\n", STDERR);
	errno = 0;
}

void	ft_display_content(char *exec_name, char *file, int fd)
{
	ssize_t	bytes_read;
	char	buf[BUF_SIZE];

	bytes_read = BUF_SIZE;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUF_SIZE);
		if (errno != 0)
		{
			ft_display_error(exec_name, file);
			break ;
		}
		write(STDOUT, buf, bytes_read);
	}
}

int	ft_cat(char **argv, int argc)
{
	int	i;
	int	fd;
	int	error;

	error = 0;
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_display_error(argv[0], argv[i]);
			error = 1;
		}
		else
			ft_display_content(argv[0], argv[i], fd);
		if (fd != -1)
			close(fd);
		i++;
	}
	return (error);
}

void	ft_cat_stdin(void)
{
	ft_display_content(NULL, NULL, STDIN);
}

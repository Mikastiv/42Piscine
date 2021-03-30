/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:43:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 10:27:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 4096

ssize_t	ft_filesize(char *filename)
{
	int		fd;
	ssize_t	bytes_read;
	ssize_t	count;
	char	buf[BUF_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	bytes_read = BUF_SIZE;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUF_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			return (-1);
		}
		count += bytes_read;
	}
	return (count);
}

char	*ft_read_file(char *filename, ssize_t size)
{
	char	*buf;
	int		fd;

	if (size == -1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = malloc(sizeof(char) * size);
	if (read(fd, buf, size) == -1)
	{
		free(buf);
		close(fd);
		return (NULL);
	}
	else
	{
		close(fd);
		return (buf);
	}
}

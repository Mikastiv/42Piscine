/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:17:14 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/31 10:26:55 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include "stdlib.h"
#include <fcntl.h>

#define BUFF_SIZE 4096

ssize_t	ft_file_size(char *filename)
{
	char	buff[BUFF_SIZE];
	ssize_t	read_res;
	ssize_t	n_bytes;
	int		fd;

	fd = open(filename, O_RDONLY);
	n_bytes = 0;
	read_res = BUFF_SIZE;
	while (read_res == BUFF_SIZE)
	{
		read_res = read(fd, buff, BUFF_SIZE);
		if (read_res == -1)
		{
			close(fd);
			return (-1);
		}
		n_bytes += read_res;
	}
	if (close(fd))
		return (-1);
	return (n_bytes);
}

char	*ft_read_file(char *filename)
{
	char	*content;
	ssize_t	size;
	int		fd;
	ssize_t	read_res;

	size = ft_file_size(filename);
	if (size == -1)
		return (NULL);
	content = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(filename, O_RDONLY);
	read_res = read(fd, content, size);
	if (read_res == -1)
	{
		close(fd);
		return (NULL);
	}
	*(content + size) = '\0';
	if (close(fd))
		return (NULL);
	return (content);
}

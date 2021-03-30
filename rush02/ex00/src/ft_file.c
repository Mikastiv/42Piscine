/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryebadok <ryebadok@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:44:32 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/27 14:24:10 by ryebadok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

ssize_t	ft_file_size(char *filename)
{
	char	buff[BUFF_SIZE];
	int		fd;
	ssize_t	n_bytes;
	ssize_t	read_res;

	fd = open(filename, O_RDONLY);
	n_bytes = 0;
	read_res = BUFF_SIZE;
	while (read_res == BUFF_SIZE)
	{
		read_res = read(fd, buff, BUFF_SIZE);
		if (read_res == -1)
			return (-1);
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
		return (NULL);
	*(content + size) = '\0';
	if (close(fd))
		return (NULL);
	return (content);
}

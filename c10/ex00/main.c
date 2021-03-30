/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:08:30 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 16:22:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterror(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	ft_argument_error(int argc)
{
	if (argc == 1)
	{
		ft_puterror("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_puterror("Too many arguments.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	buf[BUF_SIZE];
	int		fd;
	ssize_t	bytes_read;

	if (ft_argument_error(argc))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_puterror("Cannot read file.\n");
		return (0);
	}
	bytes_read = BUF_SIZE;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUF_SIZE);
		if (bytes_read == -1)
		{
			close(fd);
			ft_puterror("Cannot read file.\n");
			return (0);
		}
		write(1, buf, bytes_read);
	}
	close(fd);
}

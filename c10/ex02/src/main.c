/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:19:56 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/30 11:21:17 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include "ft_atoi.h"

int	main(int argc, char **argv)
{
	if (argc > 3)
		ft_tail(argc, argv, ft_atoi(argv[2]));
	if (argc == 3)
		ft_tail_stdin(ft_atoi(argv[2]));
}

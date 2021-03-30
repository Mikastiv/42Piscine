/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:30:30 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/29 16:50:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_cat_stdin();
		return (0);
	}
	if (ft_cat(argv, argc))
		return (1);
}

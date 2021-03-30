/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:14:15 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/29 11:11:18 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_atoi.h"
#include "ft_print.h"

int	ft_is_valid_operator(char c)
{
	return ((c == '+' || c == '-' || c == '/' || c == '*' || c == '%'));
}

int	ft_is_op_str_valid(char *str)
{
	return (ft_is_valid_operator(str[0]) && str[1] == '\0');
}

void	ft_init_ops_arr(int (*arr[5])(int, int))
{
	arr[0] = &ft_add;
	arr[1] = &ft_sub;
	arr[2] = &ft_mul;
	arr[3] = &ft_div;
	arr[4] = &ft_mod;
}

int	ft_op_index(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '*')
		return (2); 
	if (op == '/')
		return (3);
	return (4);
}

int	main(int argc, char **argv)
{
	char	operator;
	int		a;
	int		b;
	int		(*ops[5])(int, int);

	if (argc != 4)
		return (0);
	if (!ft_is_op_str_valid(argv[2]))
	{
		ft_putstr("0\n");
		return (0);
	}
	ft_init_ops_arr(ops);
	operator = *argv[2];
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (b == 0 && (operator == '/' || operator == '%'))
	{
		ft_print_error_msg(operator);
		return (0);
	}
	ft_putnbr((*ops[ft_op_index(operator)])(a, b));
	ft_putstr("\n");
}

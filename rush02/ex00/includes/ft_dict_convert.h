/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_convert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:17:54 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 15:29:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_CONVERT_H
# define FT_DICT_CONVERT_H

# include "ft_dict.h"

char	*ft_convert_num(t_dict dict, char *num);
void	ft_set_to_pow_of_10(char *mem, char first_num, unsigned int pow);

#endif
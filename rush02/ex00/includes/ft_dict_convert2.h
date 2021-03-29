/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_convert2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:26:32 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 17:43:24 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_CONVERT2_H
# define FT_DICT_CONVERT2_H

# include "ft_dict.h"

int	ft_append_hundreds(t_dict dict, char *dest, char *num);
int	ft_append_tens_and_units(t_dict dict, char *dest, char *num);
int	conv_3num(t_dict dict, char *dest, char *num);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:13:22 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/28 11:50:07 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT2_H
# define FT_DICT2_H

# include "ft_dict.h"

t_dict	ft_create_dict(char **entries);
t_entry	*ft_find_entry(t_dict dict, char *key);

#endif

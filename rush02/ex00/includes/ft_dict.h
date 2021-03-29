/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:52:45 by ryebadok          #+#    #+#             */
/*   Updated: 2021/03/28 11:46:51 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef t_entry**	t_dict;

int		ft_is_dict_valid(char **dict);
void	ft_replace_newlines(char *str);
t_dict	ft_load_dictionary(char *filename);
void	ft_free_dict(t_dict dict);

#endif

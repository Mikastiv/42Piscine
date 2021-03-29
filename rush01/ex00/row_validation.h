/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:34:05 by mleblanc          #+#    #+#             */
/*   Updated: 2021/03/21 15:50:18 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROW_VALIDATION_H
# define ROW_VALIDATION_H
# include "config.h"

int	ft_dup_in_row(int result[][N], int row);
int	ft_is_rowleft_valid(int result[][N], int clue, int row);
int	ft_is_rowright_valid(int result[][N], int clue, int row);
int	ft_rowleft_first_col_valid(int result[][N], int clue, int row, int col);
int	ft_rowright_first_col_valid(int result[][N], int clue, int row, int col);

#endif

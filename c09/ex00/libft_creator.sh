# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 10:47:42 by mleblanc          #+#    #+#              #
#    Updated: 2021/03/25 10:52:06 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
find . -maxdepth 1 -type f -name "*.c" -exec gcc -Wall -Wextra -Werror -c {} ';'
ar rcs libft.a *.o
find . -maxdepth 1 -type f -name "*.o" -delete

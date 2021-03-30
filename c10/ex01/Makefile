# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 12:52:58 by mleblanc          #+#    #+#              #
#    Updated: 2021/03/30 11:55:22 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/ft_cat.c src/ft_string.c
OBJS	= $(SRCS:.c=.o)
NAME	= ft_cat
INCS	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

all:		$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 10:19:16 by mleblanc          #+#    #+#              #
#    Updated: 2021/03/31 10:14:40 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(wildcard src/*.c)
OBJS	= $(SRCS:.c=.o)
INCS	= includes
NAME	= bsq
CC		= clang
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
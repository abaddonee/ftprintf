# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: likiffel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 22:34:30 by likiffel          #+#    #+#              #
#    Updated: 2024/03/10 23:35:46 by likiffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC	= ft_printf.c ft_put.c ft_itohex.c

OBJS			= $(SRC:.c=.o)

CC				= gcc
CFLAGS			= -Wextra -Wall -Werror
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

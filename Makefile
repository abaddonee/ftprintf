# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: likiffel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 22:34:30 by likiffel          #+#    #+#              #
#    Updated: 2024/03/10 22:48:46 by likiffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC	= ft_printf.c ft_auxilliaire_1.c ft_auxilliaire_2.c

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

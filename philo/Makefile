# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 19:48:08 by acastilh          #+#    #+#              #
#    Updated: 2023/09/06 19:59:14 by acastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	=	error.c \
			main.c \
			utils.c \
			init.c \
			philo.c \
			routine.c \
			time.c \

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror -pthread

$(NAME):	$(OBJS)
			cc $^ $(CFLAGS) -o $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)
			
fclean:		clean
			rm -f $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re

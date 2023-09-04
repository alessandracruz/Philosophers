# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 19:48:08 by acastilh          #+#    #+#              #
#    Updated: 2023/09/04 08:29:24 by acastilh         ###   ########.fr        #
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

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --track-origins=yes  --log-file=project.log \
	./philo 4 310 200 100
	./philo 1 200 200 200
	./philo 1 800 200 200
	./philo 2 800 200 200 7
	./philo 5 800 200 200 7
	./philo 5 800 200 200 7
	./philo 4 410 200 200 7
	./philo 4 310 200 200
	./philo 4 310 200 100
	./philo 4 2147483647 200 200 7
	./philo 4 200 210 200
	cat project.log

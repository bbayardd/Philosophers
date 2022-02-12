# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 12:06:41 by bbayard           #+#    #+#              #
#    Updated: 2022/02/10 12:06:43 by bbayard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	philo.c \
		run.c\
		utils.c\
		print.c\

INCLUDE = philo.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -I./include -o $(NAME)

clean :
	@rm -rf

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all

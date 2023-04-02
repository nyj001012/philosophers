# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 13:01:21 by yena              #+#    #+#              #
#    Updated: 2023/04/02 12:20:41 by yena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = ./main.c\
	   ./life_of_philosophers.c\
	   ./routine.c\
	   ./util/common_util.c\
	   ./util/print_util.c\
	   ./util/initialize_util.c\
	   ./util/monitoring_util.c\
	   ./util/validation_util.c

OBJS   = $(SRCS:.c=.o)
INC	   = -I include

CC	   = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM	   = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


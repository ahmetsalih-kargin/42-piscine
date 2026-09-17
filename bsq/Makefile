# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 21:29:24 by muhamalt          #+#    #+#              #
#    Updated: 2026/09/16 21:29:26 by muhamalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c read.c parse.c solve.c print.c utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c bsq.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

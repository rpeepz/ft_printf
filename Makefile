# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 21:22:38 by rpapagna          #+#    #+#              #
#    Updated: 2019/04/10 20:13:17 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= printf_test

CFLAGS	= -Wall -Werror -Wextra -L libft/ -lft
INCL	= -I includes/ft_printf.h

SRCS 	= srcs/do_things.c \
		srcs/finders.c \
		srcs/ft_printf.c \
		srcs/get_mods.c \
		printf_convert/convert_c.c \
		printf_convert/convert_d.c \
		printf_convert/convert_percent.c \
		main.c

all:	$(NAME)

$(NAME):
		@echo "Building test program"
		gcc -g -o $(NAME) $(CFLAGS) $(SRCS) $(INCL)
		@echo "done"

clean:
		make -C libft clean

fclean: clean
		make -C libft fclean
		rm -f $(NAME)
		rm -rf $(NAME).dSYM

re: fclean all

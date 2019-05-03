# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpapagna <rpapagna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 21:22:38 by rpapagna          #+#    #+#              #
#    Updated: 2019/05/03 01:10:20 by rpapagna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra
INCL	= -I includes/

SRCS 	= do_things.c \
		finders.c \
		ft_printf.c \
		get_mods.c

CONV	= convert_c.c \
		convert_f.c \
		convert_i.c \
		convert_o.c \
		convert_p.c \
		convert_percent.c \
		convert_s.c \
		convert_u.c \
		convert_x.c \
		convert_b.c

LIBS	= ft_atoi.c \
		ft_bzero.c \
		ft_countwords.c \
		ft_intlen.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_itoa_base.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pipewrench.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strchri.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcnew.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strpop.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

OBJ		= $(patsubst %.c,%.o,$(SRCS))
OBJ		+= $(patsubst %.c,%.o,$(CONV))
OBJ		+= $(patsubst %.c,%.o,$(LIBS))

#COLOR OUTPUT OPIONS
RED		=\033[0;31m
GREEN	=\033[0;32m
YELLOW	=\033[0;33m
NC		=\033[0m

all:	$(NAME)

$(NAME):
		@printf "$(GREEN)[$(NAME)$(NC)] Building [.:]\r"
		@gcc $(CFLAGS) -c $(addprefix srcs/,$(SRCS)) $(addprefix printf_convert/,$(CONV)) $(addprefix libft/, $(LIBS)) $(INCL)
		@printf "$(GREEN)[$(NAME)$(NC)] Building [:.]\r"
		@ar -rcs $(NAME) $(OBJ)
		@printf "$(GREEN)[$(NAME)$(NC)] Building [.:]\r"
		@printf "$(GREEN)[$(NAME)]$(RED) Build complete! [OK]$(NC)\n"

clean:
		@rm -rf $(OBJ)
		@printf "$(YELLOW)[libftprintf.a]$(NC) Removed object files!\n$(NC)"

fclean: clean
		@rm -rf $(NAME)
		@printf "$(YELLOW)[libftprintf.a]$(RED) Removed $(NAME)!\n$(NC)"

re: fclean all
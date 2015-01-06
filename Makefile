#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 14:34:24 by sdurr             #+#    #+#              #
#    Updated: 2015/01/06 17:18:15 by getrembl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= libftprintf.a

CPATH			= ./src/

SRC				= ft_print_c.c \
					ft_print_o.c \
					ft_print_p.c \
					ft_print_b.c \
					ft_print_d_plus.c \
					ft_long_long.c \
					ft_print_d_long.c \
					ft_putnbr_long.c \
					ft_litoa.c \
					ft_print_u.c \
					ft_print_s.c \
					ft_printf.c \
					ft_print_d.c \
					ft_print_x.c \
					ft_print_x_maj.c \
					ft_type.c \
					ft_test_type.c \

OBJ				= $(SRC:.c=.o)

CC				= gcc

export CFLAGS	= -Wall -Wextra -Werror

HPATH       	= -I libft/includes/

LIBFT_DIR		= libft

LIBFT			= (LIBFT_DIR) /libft

LIB				= -lft -lftprintf

all			:	$(NAME) $(LIBFT)

$(NAME)		:	$(OBJ)
					ar rc $(NAME) $(OBJ)
					ranlib $(NAME)

$(LIBFT)	:
					@(cd $(LIBFT_DIR) && $(MAKE) -f Makefile)

.c.o		:	$(CPATH)%.c
					$(CC) $(CFLAGS) $(HPATH) -c $(SRC) $(LIB)

clean		:
					rm -rf $(OBJ)
					rm -rf *~
					@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean		:	clean
					rm -rf $(NAME)
					@(cd $(LIBFT_DIR) && $(MAKE) $@)

re			:	fclean all
					@(cd $(LIBFT_DIR) && $(MAKE) $@)

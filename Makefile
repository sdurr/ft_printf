#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 14:34:24 by sdurr             #+#    #+#              #
#    Updated: 2015/01/09 10:53:08 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= libftprintf.a

CPATH			= ./src/

SRC				= ft_litoa.c \
					ft_putwchar.c \
					ft_putwstr.c \
					ft_wstrlen.c \
					ft_llitoa.c \
					ft_llonglen.c \
					ft_longlen.c \
					ft_print_b.c \
					ft_print_c.c \
					ft_print_c_maj.c \
					ft_print_d.c \
					ft_print_d_long_long.c \
					ft_print_d_maj.c \
					ft_print_d_plus.c \
					ft_print_o.c \
					ft_print_o_maj.c \
					ft_print_p.c \
					ft_print_s.c \
					ft_print_s_maj.c \
					ft_print_d_size_t.c \
					ft_print_u.c \
					ft_print_u_maj.c \
					ft_print_x.c \
					ft_print_x_long.c \
					ft_print_x_maj.c \
					ft_print_x_maj_size_t.c \
					ft_print_x_maj_long.c \
					ft_print_x_size_t.c \
					ft_printf.c \
					ft_putnbr_long.c \
					ft_type.c \

OBJ				= $(SRC:.c=.o)

CC				= gcc

export CFLAGS	= -Wall -Wextra -Werror

HPATH       	= -I libft

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

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 14:34:24 by sdurr             #+#    #+#              #
#    Updated: 2014/12/28 14:25:39 by sdurr            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libftprint.a

CPATH		= ./src/

SRC			= ft_print_c.c \
				ft_print_u.c \
				ft_print_s.c \
				ft_printf.c \
				ft_print_d.c \
				ft_print_x.c \
				ft_print_x_diese.c \
				ft_type.c \
				ft_test_type.c \

OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

HPATH       = -I libft/includes/

all		:		$(NAME)

$(NAME)	:		$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

.c.o:		$(CPATH)%.c
				make -C libft
				$(CC) $(CFLAGS) $(HPATH) libft/includes/ -c $(SRC)

clean	:
				rm -rf $(OBJ)
				rm -rf *~

fclean	:		clean
				rm -rf $(NAME)

re		:		fclean all

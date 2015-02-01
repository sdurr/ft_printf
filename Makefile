#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 14:34:24 by sdurr             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2015/01/22 18:43:08 by getrembl         ###   ########.fr        #
=======
#    Updated: 2015/01/26 10:34:40 by sdurr            ###   ########.fr        #
>>>>>>> 5fedfb12a0f083662ba9297865fa4cdfbcf4e522
#                                                                              #
#******************************************************************************#

NAME			= libftprintf.a

CPATH			= ./src/

SRC				= 	ft_unimask.c \
					ft_dectobin.c \
					ft_split_int_etoile.c \
					ft_calc_and_print_wchar.c \
					ft_calc_wstr.c \
					ft_bintodec.c \
					ft_otoc.c \
					ft_atoull.c \
					ft_litoa.c \
					ft_llitoa.c \
					ft_llonglen.c \
					ft_longlen.c \
					ft_max_plus.c \
					ft_max_plus_ascii.c \
					ft_max_plus_unsigned.c \
					ft_nbudigit.c \
					ft_number_befor_char.c \
					ft_op_base_16.c \
					ft_op_base_8.c \
					ft_op_base_8_long.c \
					ft_op_base_8_ulong.c \
					ft_op_base_8_uint.c \
					ft_op_base_16_int.c \
					ft_op_base_16_size_t.c \
					ft_op_base_16_long.c \
					ft_print_modulo.c \
					ft_print_b.c \
					ft_print_c.c \
					ft_print_c_maj.c \
					ft_print_d.c \
					ft_print_d_long_long.c \
					ft_print_d_maj.c \
					ft_print_d_h.c \
					ft_print_o_h.c \
					ft_print_u_h.c \
					ft_print_x_h.c \
					ft_print_x_maj_h.c \
					ft_print_d_plus.c \
					ft_print_o.c \
					ft_print_o_maj.c \
					ft_print_p.c \
					ft_print_s.c \
					ft_print_s_maj.c \
					ft_print_u.c \
					ft_print_u_maj.c \
					ft_print_x.c \
					ft_print_x_long.c \
					ft_print_x_maj.c \
					ft_print_x_maj_size_t.c \
					ft_print_x_maj_long.c \
					ft_print_x_size_t.c \
					ft_print_d_size_t.c \
					ft_print_u_size_t.c \
					ft_print_o_size_t.c \
					ft_printf.c \
					ft_putnbr_long.c \
					ft_putwchar.c \
					ft_recursive_power.c \
					ft_space_number.c \
					ft_type.c \
					ft_uitoa.c \
					ft_wstrlen.c \
					ft_atoi.c \
					ft_atoull.c \
					ft_itoa.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_revers.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlen.c \
					ft_strnew.c \
					ft_long_int.c \

OBJ				= $(SRC:.c=.o)

CC				= gcc

export CFLAGS	= -Wall -Wextra -Werror

HPATH       	= -I libft

LIB				= -lftprintf

all			:	$(NAME)

$(NAME)		:	$(OBJ)
					ar rc $(NAME) $(OBJ)
					ranlib $(NAME)



.c.o		:	$(CPATH)%.c
					$(CC) $(CFLAGS) $(HPATH) -c $(SRC) $(LIB)

clean		:
					rm -rf $(OBJ)
					rm -rf *~

fclean		:	clean
					rm -rf $(NAME)

re			:	fclean all

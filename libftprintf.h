/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:12:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/08 13:07:06 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

char		*ft_litoa(long n);

int			ft_printf(char *format, ...);
int			ft_print_b(va_list ap, char *s, int j, char **aff);
int			ft_print_c(va_list ap, char *s, int j, char **aff);
int			ft_print_size_t(va_list ap, char *s, int j, char **aff);
int			ft_print_c_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_d(va_list ap, char *s, int j, char **aff);
int			ft_print_d_maj(va_list ap, char *s, int i, char **aff);
int			ft_print_d_long_long(va_list ap, char *s, int i, char **aff);
int			ft_print_s_maj(va_list ap, char *s, int i, char **aff);
int			ft_print_d_plus(va_list ap, char **aff);
int			ft_print_o(va_list ap, char *s, int j, char **aff);
int			ft_print_o_long(va_list ap, char *s, int j, char **aff);
int			ft_print_u_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_p(va_list ap, char *s, int j, char **aff);
int			ft_print_s(va_list ap, char *s, int j, char **aff);
int			ft_print_u(va_list ap, char *s, int j, char **aff);
int			ft_print_x(va_list ap, char *s, int j, char **aff);
int			ft_print_x_long(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj_long(va_list ap, char *s, int j, char **aff);
int			ft_print_x_diese(va_list ap, char **aff);
int			ft_test_type(char *s);
int			ft_type(char *s, int i, va_list ap, char **aff);

size_t		ft_longlen(long l);

void		ft_putnbr_long(long n);

#endif

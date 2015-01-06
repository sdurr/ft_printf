/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:12:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 19:57:25 by getrembl         ###   ########.fr       */
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
int			ft_print_d(va_list ap, char *s, int j, char **aff);
int			ft_print_d_long(va_list ap, char **aff);
int			ft_print_d_maj(va_list ap);
int			ft_print_d_plus(va_list ap, char **aff);
int			ft_print_o(va_list ap, char *s, int j, char **aff);
int			ft_print_p(va_list ap, char *s, int j, char **aff);
int			ft_print_s(va_list ap, char *s, int j, char **aff);
int			ft_print_u(va_list ap, char *s, int j, char **aff);
int			ft_print_x(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_x_diese(va_list ap, char **aff);
int			ft_test_type(char *s);
int			ft_type(char *s, int i, va_list ap, char **aff);

long		ft_long_long(long n);

void		ft_putnbr_long(long n);

#endif

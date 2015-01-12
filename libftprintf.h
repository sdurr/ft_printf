/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:12:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/12 14:41:41 by sdurr            ###   ########.fr       */
/*   Updated: 2015/01/12 10:04:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

char		*ft_litoa(long n);
char		*ft_llitoa(long long ll);

int			ft_printf(char *format, ...);
int			ft_print_b(va_list ap, char *s, int j, char **aff);
int			ft_print_c(va_list ap, char *s, int j, char **aff);
int			ft_print_d_size_t(va_list ap, char *s, int j, char **aff);
int			ft_space_number(char *s, int j, char **aff);
int			ft_print_o_size_t(va_list ap, char *s, int j, char **aff);
int			ft_print_c_maj(va_list ap, char *s, int j);
int			ft_print_d(va_list ap, char *s, int j, char **aff);
int			ft_print_d_maj(va_list ap, char *s, int i, char **aff);
int			ft_print_d_long_long(va_list ap, char *s, int i, char **aff);
int			ft_print_d_plus(va_list ap, char *s, int i, char **aff);
int			ft_print_o(va_list ap, char *s, int j, char **aff);
int			ft_print_d_h(va_list ap, char *s, int j, char **aff);
int			ft_print_x_h(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj_h(va_list ap, char *s, int j, char **aff);
int			ft_print_o_h(va_list ap, char *s, int j, char **aff);
int			ft_print_u_h(va_list ap, char *s, int j, char **aff);
int			ft_print_o_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_p(va_list ap, char *s, int j, char **aff);
int			ft_print_s(va_list ap, char *s, int j, char **aff);
int			ft_print_s_maj(va_list ap, char *s, int i);
int			ft_print_u(va_list ap, char *s, int j, char **aff);
int			ft_print_u_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_x(va_list ap, char *s, int j, char **aff);
int			ft_print_x_size_t(va_list ap, char *s, int j, char **aff);
int			ft_print_u_size_t(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj_size_t(va_list ap, char *s, int j, char **aff);
int			ft_print_x_long(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj(va_list ap, char *s, int j, char **aff);
int			ft_print_x_maj_long(va_list ap, char *s, int j, char **aff);
int			ft_print_x_diese(va_list ap, char **aff);
int			ft_space_number(char *s, int i, char **aff);
int			ft_test_type(char *s);
int			ft_type(char *s, int i, va_list ap, char **aff);

size_t		ft_wstrlen(wchar_t *s);
size_t		ft_llonglen(long long ll);
size_t		ft_longlen(long l);

void		ft_putnbr_long(long n);
void		ft_putwstr(wchar_t *s);
void		ft_putwchar(wchar_t c);

#endif

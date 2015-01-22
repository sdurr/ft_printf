/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:12:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 08:57:57 by sdurr            ###   ########.fr       */
/*   Updated: 2015/01/12 10:04:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

char				*ft_litoa(long n);
char				*ft_llitoa(long long ll);
char				*ft_op_base_16(char *hexa, int rest, unsigned int *q);
char				*ft_op_base_8(char *octal, int rest, size_t *q);
char				*ft_op_base_8_long(char *octal, int rest, long long *q);
char				*ft_base_8_unsig_long(char *octal, int rest, unsigned long *q);
char				*ft_op_base_8_unsigned_int(char *oc, int rest, unsigned int *q);
char				*ft_op_base_16_int(char *hexa, int rest, int *q);
char				*ft_op_base_16_size_t(char *hexa, int rest, size_t *q);
char				*ft_op_base_16_long(char *hexa, int rest, unsigned long long *q);
char				*ft_uitoa(unsigned int n);
char				*ft_dectobin(unsigned int dec);
char				*ft_unimask(char *bin, size_t digit);

int					ft_printf(char *format, ...);
int					ft_number_befor_char(char *s1, char *s, int j, char **aff);
int					ft_print_b(va_list ap, char *s, int j, char **aff);
int					ft_print_c(va_list ap, char *s, int j, char **aff);
int					ft_print_c_maj(va_list ap, char *s, int i, char **aff);
int					ft_print_d(va_list ap, char *s, int j, char **aff);
int					ft_print_d_maj(va_list ap, char *s, int i, char **aff);
int					ft_print_d_long_long(va_list ap, char *s, int i, char **aff);
int					ft_print_d_plus(va_list ap, char *s, int i, char **aff);
int					ft_print_d_size_t(va_list ap, char *s, int j, char **aff);
int					ft_print_d_h(va_list ap, char *s, int j, char **aff);
int					ft_print_modulo(char *s, int j, char **aff);
int					ft_print_o(va_list ap, char *s, int j, char **aff);
int					ft_print_o_h(va_list ap, char *s, int j, char **aff);
int					ft_print_u_h(va_list ap, char *s, int j, char **aff);
int					ft_print_o_maj(va_list ap, char *s, int j, char **aff);
int					ft_print_o_size_t(va_list ap, char *s, int j, char **aff);
int					ft_print_p(va_list ap, char *s, int j, char **aff);
int					ft_print_s(va_list ap, char *s, int j, char **aff);
int					ft_print_s_maj(va_list ap, char *s, int i);
int					ft_print_u(va_list ap, char *s, int j, char **aff);
int					ft_print_u_maj(va_list ap, char *s, int j, char **aff);
int					ft_print_u_size_t(va_list ap, char *s, int j, char **aff);
int					ft_print_x(va_list ap, char *s, int j, char **aff);
int					ft_print_x_size_t(va_list ap, char *s, int j, char **aff);
int					ft_print_x_h(va_list ap, char *s, int j, char **aff);
int					ft_print_x_maj_h(va_list ap, char *s, int j, char **aff);
int					ft_print_x_maj_size_t(va_list ap, char *s, int j, char **aff);
int					ft_print_x_long(va_list ap, char *s, int j, char **aff);
int					ft_print_x_maj(va_list ap, char *s, int j, char **aff);
int					ft_print_x_maj_long(va_list ap, char *s, int j, char **aff);
int					ft_print_x_diese(va_list ap, char **aff);
int					ft_recursive_power(int nb, int power);
int					ft_space_number(char *s, int i, char **aff);
int					ft_test_type(char *s);
int					ft_type(char *s, int i, va_list ap, char **aff);
int					ft_max_plus(int i);
int					ft_max_plus_ascii(int i);
int					ft_calc_and_print_wchar(unsigned int wc, int j, char *tmp);

size_t				ft_llonglen(long long ll);
size_t				ft_longlen(long l);
size_t				ft_nbudigit(unsigned int n);
size_t				ft_wstrlen(wchar_t *s);

unsigned int		*ft_otoc(char *s, unsigned int nbyte);
unsigned int		ft_atoui(const char *str);
unsigned int		ft_max_plus_unsigned (unsigned int i);
unsigned int		ft_bintodec(unsigned int n);
unsigned int		*ft_split_int_etoile(char *s);

unsigned long long	ft_atoull(const char *str);

void				ft_putnbr_long(long n);
void				ft_putwstr(wchar_t *s);
void				ft_putwchar(unsigned int *c);

#endif

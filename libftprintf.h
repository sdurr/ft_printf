/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:12:02 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 14:26:04 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

# include <stdarg.h>

int		ft_print_c(va_list ap);
int		ft_print_d(va_list ap);
int		ft_print_u(va_list ap);
int		ft_print_s(va_list ap);
int		ft_print_x(va_list ap);
int		ft_print_x_diese(va_list ap);
int		ft_printf(char *format, ...);
int		ft_type(char *s, int i, va_list ap);
int		ft_test_type(char *s);

#endif
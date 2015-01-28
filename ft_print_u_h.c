/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:48:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include <limits.h>

int				ft_print_u_h(va_list ap, char *s, int i, char **aff)
{
	unsigned int	d;
	int				j;
	int				test;

	test = 0;
	j = 0;
	i--;
	if (s[i] == 'h' && s[i - 1] == 'h')
		test = 1;
	if (s[i] >= '0' && s[i] <= '9')
		j++;
	d = va_arg(ap, unsigned int);
	if (d > 255 && test == 1)
		d = ft_max_plus_unsigned(d);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0))
		return (0);
	if (s[i] == ' ' && j == 0)
		*aff = ft_strjoin(*aff, " ");
	j = ft_number_befor_char(ft_litoa(d), s, i, aff);
	if (s[i] == '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	if (s[i] != '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

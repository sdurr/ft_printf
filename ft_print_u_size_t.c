/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:47:46 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "limits.h"

int					ft_print_u_size_t(va_list ap, char *s, int i, char **aff)
{
	size_t			d;

	i--;
	d = va_arg(ap, unsigned long);
	if (d == ULONG_MAX)
	{
		*aff = ft_strjoin(*aff, "18446744073709551615");
		return (0);
	}
	if (d == 0)
	{
		if (s[i] != '.')
			*aff = ft_strjoin (*aff, "0");
		return (0);
	}
	ft_number_befor_char(ft_litoa((long)d), s, i, aff);
	*aff = ft_strjoin(*aff, ft_litoa(d));
	return (0);
}

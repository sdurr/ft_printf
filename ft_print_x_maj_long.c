/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 17:59:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <limits.h>

int			ft_print_x_maj_long(va_list ap, char *s, int j, char **aff)
{
	char					*hexa;
	unsigned long long		quotient;

	quotient = va_arg(ap, unsigned long long);
	if (quotient == 0)
	{
		*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	if (quotient == ULLONG_MAX)
	{
		*aff = ft_strjoin(*aff, "FFFFFFFFFFFFFFFF");
		return (0);
	}
	hexa = ft_strnew(15);
	hexa = ft_op_base_16_long(hexa, 1, &quotient);
	hexa = ft_revers(hexa);
	quotient = ft_number_befor_char(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0X");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

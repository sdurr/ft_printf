/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 17:57:07 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include <stdarg.h>
#include "libftprintf.h"

int					ft_print_x_long(va_list ap, char *s, int j, char **aff)
{
	char					*hexa;
	unsigned long long		quotient;

	quotient = va_arg(ap, unsigned long long);
	if (quotient == 0)
	{
		if (s[j - 1] != '0' && s[j - 1] != '.')
			*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	if (quotient > ULLONG_MAX)
	{
		*aff = ft_strjoin(*aff, "ffffffffffffffff");
		return (0);
	}
	hexa = ft_strnew(9);
	hexa = ft_op_base_16_long(hexa, 0, &quotient);
	hexa = ft_revers(hexa);
	quotient = ft_number_befor_char(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0x");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

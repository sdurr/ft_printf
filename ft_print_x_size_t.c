/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/30 09:13:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int					ft_print_x_size_t(va_list ap, char *s, int j, char **aff)
{
	char			*hexa;
	size_t			quotient;

	quotient = va_arg(ap, int);
	if ((quotient == 0 && s[j - 1] == '.')
		|| (quotient == 0 && s[j - 1] == '0'))
		return (0);
	if (quotient == 0)
	{
		if (s[j - 1] != '0' && s[j - 1] != '.')
			*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	hexa = ft_strnew(9);
	hexa = ft_op_base_16_size_t(hexa, 0, &quotient);
	quotient = ft_number_befor_char(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0x");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

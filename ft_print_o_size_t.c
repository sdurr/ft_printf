/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 22:44:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/24 11:46:01 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <limits.h>

int					ft_print_o_size_t(va_list ap, char *s, int j, char **aff)
{
	char			*octal;
	size_t			q;
	int				i;

	q = va_arg(ap, size_t);
	i = j;
	while (s[i] != '%')
		i--;
	if (s[i + 1] == '#')
		*aff = ft_strjoin(*aff, "0");
	if (q == ULLONG_MAX)
	{
		*aff = ft_strjoin(*aff, "1777777777777777777777");
		return (0);
	}
	if ((octal = ft_strnew(12)) && q == 0)
	{
		*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	octal = ft_op_base_8(octal, 0, &q);
	q = ft_number_befor_char(octal, s, --j, aff);
	*aff = ft_strjoin(*aff, octal);
	return (0);
}

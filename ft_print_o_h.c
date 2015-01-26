/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 22:44:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/24 11:45:21 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int			ft_number_befor(char *s1, char *s, int i, char **aff)
{
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_number_befor_char(s1, s, i, aff);
	return (0);
}

int					ft_print_o_h(va_list ap, char *s, int j, char **aff)
{
	char			*octal;
	unsigned int	q;
	int				i;

	q = va_arg(ap, unsigned int);
	i = j;
	if (s[i - 1] == 'h' && s[i - 2] == 'h')
		q = ft_max_plus_unsigned(q);
	if (s[i - 1] == 'h' && s[i - 2] != 'h' && (int)q < 0)
		while ((int)q < 0 && (*aff = ft_strjoin(*aff, "1")))
			q = 127 + 32767 + (q - 127) + 1;
	while (s[i] != '%')
		i--;
	if (s[i + 1] == '#')
		*aff = ft_strjoin(*aff, "0");
	if ((q == 0 && s[j - 1] == '.') || (q == 0 && s[j - 1] == '0')
		|| (q == 0 && s[i + 1] != '#' && (*aff = ft_strjoin(*aff, "0"))))
		return (0);
	octal = ft_strnew(12);
	octal = ft_op_base_8_unsigned_int(octal, 0, &q);
	q = ft_number_befor(octal, s, j, aff);
	*aff = ft_strjoin(*aff, octal);
	return (0);
}

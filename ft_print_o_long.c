/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 22:44:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/21 10:35:04 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>

static int		ft_number_befor(char *s1, char *s, int i, char **aff)
{
	size_t j;

	j = 0;
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_number_befor_char(j, s, i, aff);
	return (0);
}

static int		ft_print_o_negative_long(long int d, char *s, int j, char **aff)
{
	unsigned long int	quotient;
	int					rest;
	int					i;
	char				*octal;

	octal = ft_strnew(12);
	quotient = 4294967296 + d;
	i = 0;
	octal = ft_op_base_8_long(octal, 0, &quotient);
	quotient = ft_number_befor(octal, s, j, aff);
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

int				ft_print_o_long(va_list ap, char *s, int j, char **aff)
{
	char			*octal;
	long int		quotient;
	int				rest;
	int				i;

	quotient = va_arg(ap, long int);
	i = j;
	while (s[i] != '%')
		i--;
	if (s[i + 1] == '#')
		*aff = ft_strjoin(*aff, "0");
	if (quotient < 0)
		return ((ft_print_o_negative_long(quotient, s, j, aff)));
	if ((quotient == 0 && s[j - 1] == '.')
		|| (quotient == 0 && s[j - 1] == '0' && s[j - 2] == '.'))
		return (0);
	if (quotient == 0 && (*aff = ft_strjoin(*aff, "0")))
		return (0);
	octal = ft_strnew(12);
	octal = ft_op_base_8_long(octal, 0, &quotient);
	quotient = ft_number_befor(octal, s, j, aff);
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:07:34 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static int		ft_minim(int ret, char *aff, int i, char *s)
{
	ret += ft_strlen(aff);
	ft_putstr(aff);
	ret += 1;
	while (s[++i])
		ret += 1;
	return (ret);
}

static int		test_i(char *s, int i, int test, char **s1)
{
	if (test == 0)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '#' || s[i] == '+'
			|| s[i] == 'l' || s[i] == ' ' || s[i] == '.' || s[i] == '-'
			|| s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
			return (1);
	}
	if (test == 1)
	{
		ft_putstr(s1[1]);
		i += ft_strlen(s1[1]);
		return (i);
	}
	return (0);
}

static int		ft_printf_suite(va_list ap, int *i, char *s[4])
{
	while (s[0][++i[0]] && (s[1] = ft_strnew(12)))
	{
		while (s[0][i[0]] != '%' && s[0][i[0]] && (s[2][0] = s[0][i[0]++]))
			s[1] = ft_strjoin(s[1], s[2]);
		i[1] = test_i(s[0], i[1], 1, s);
		if ((s[1] = ft_strnew(12)) && (i[0]++) >= 0)
			while ((test_i(s[0], i[0], 0, s)) == 1)
				(i[0])++;
		if ((i[2] = ft_type(s[0], i[0], ap, &s[1])) == -1)
			i[0]--;
		if (i[2] > 0 && i[2] != -2)
			i[1] = i[2] + i[1];
		if (i[2] == -2)
			return (ft_minim(i[1], s[1], i[0], s[0]));
		i[1] = test_i(s[0], i[1], 1, s);
	}
	return (i[1]);
}

int				ft_printf(char *format, ...)
{
	va_list	ap;
	int		i[3];
	char	*s[4];

	s[0] = ft_strdup(format);
	i[0] = -1;
	i[1] = 0;
	va_start(ap, format);
	s[2] = ft_strnew(2);
	return (ft_printf_suite(ap, i, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/30 14:12:13 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static int		ft_minim(int ret, char *aff, int i, char *s)
{
	ret += ft_strlen(aff);
	if ((aff = ft_strchr(aff, '0')) != NULL)
		ft_putstr(aff);
	if (s[i - 1] == '.')
		ret += 1;
	while (s[++i])
		ret += 1;
	return (ret);
}

static int		test_i(char *s, int i)
{
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '#'|| s[i] == '+'
		|| s[i] == 'l' || s[i] == ' ' || s[i] == '.' || s[i] == '-'
		|| s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
		return (1);
	return (0);
}

int				ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	char	**s;
	int		ret;
	int		test;

	s = (char **)malloc(sizeof(char *) * 4);
	s[0] = ft_strdup(format);
	i = -1;
	ret = 0;
	va_start(ap, format);
	s[2] = ft_strnew(2);
	while (s[0][++i] && (s[1] = ft_strnew(1)))
	{
		while (s[0][i] != '%' && s[0][i] && (s[2][0] = s[0][i++]))
			s[1] = ft_strjoin(s[1], s[2]);
		ft_putstr(s[1]);
		ret += ft_strlen(s[1]);
		s[1] = ft_strnew(1);
		i++;
		while ((test_i(s[0], i)) == 1)
			i++;
		if ((test = ft_type(s[0], i, ap, &s[1])) == -1)
				i--;
		if (test > 0 && test != -2)
			ret = test + ret;
		if (test == -2)
			return (ft_minim(ret, s[1], i, s[0]));
		ft_putstr(s[1]);
		ret += ft_strlen(s[1]);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/31 10:46:39 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libftprintf.h"

static void		ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i--] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		if ((s[i] == ' ' && j > 0) || (s[i + 1] == '0' && j > 0))
		{
			*aff = ft_strjoin(*aff, " ");
			j--;
		}
		while (j-- > stop)
		{
			if (s[i + 1] == '0')
				*aff = ft_strjoin(*aff, "0");
			else
				*aff = ft_strjoin(*aff, " ");
		}
	}
}

static int		test_e(char s, int d, char **aff, int j)
{
	if (s == ' ' && d >= -9)
		*aff = ft_strjoin(*aff, " ");
	if (s == '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	if (s == ' ' && j > 0)
		j--;
	return (j);
}

static int		test_1(char *s, int i, char **aff, int d)
{
	if ((d < 0 && d > -2147483648 && s[i + 1] == '0' && s[i + 1] != ' ')
		|| (d < 0 && d > -2147483648 && s[i] == '.' && s[i + 1] != ' '))
	{
		*aff = ft_strjoin(*aff, "-");
		return (1);
	}
	return (0);
}

static void		check(char *s, int i, char **aff)
{
	if (s[i] == '.' || s[i + 1] == '0')
		*aff = ft_strjoin(*aff, "0");
	else
		*aff = ft_strjoin(*aff, " ");
}

int				ft_print_d(va_list ap, char *s, int i, char **aff)
{
	int			d;
	size_t		j;
	char		*tmp;

	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, int);
	if (((test_1(s, i, aff, d)) == 1) && (d = d * -1))
		if (j > 0 && s[i] != '.')
			j--;
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0 && s[i - 1] == '%' && j == 0))
		return (0);
	j = test_e(s[i], d, aff, j);
	ft_point_space(s, i, aff, j);
	while (j-- > (ft_strlen(ft_itoa(d))))
		check(s, i, aff);
	if (s[i] != '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/28 14:07:55 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libftprintf.h"

static int		ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (stop == 0)
		stop = 1;
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
		if (j > 0)
			while (j-- > stop)
			{
				if (s[i + 1] == '0')
					*aff = ft_strjoin(*aff, "0");
				else
					*aff = ft_strjoin(*aff, " ");
			}
	}
	return (0);
}

int				ft_print_d(va_list ap, char *s, int i, char **aff)
{
	int			d;
	char		*tmp;
	size_t		j;
	int			test;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	test = 0;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, int);
	if ((d < 0 && d > -2147483648 && s[i + 1] == '0' && s[i + 1] != ' ')
		|| (d < 0 && d > -2147483648 && s[i] == '.' && s[i + 1] != ' '))
	{
		*aff = ft_strjoin(*aff, "-");
		d = d * -1;
		test = -1;
		if (j > 0 && s[i] != '.')
			j--;
	}
	if (j < ft_strlen (ft_itoa(d)) && d > 0)
		j = ft_strlen (ft_itoa(d));
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0 && s[i - 1] == '%' && j == 0))
		return (0);
	if (s[i] == ' ' && d >= -9)
		*aff = ft_strjoin(*aff, " ");
	if (test == -1)
		ft_point_space(s, test, aff, j);
	else
		ft_point_space(s, i, aff, j);
	if (s[i] == '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	if (s[i] == ' ' && j > 0)
		j--;
	while (j-- > (ft_strlen(ft_itoa(d))))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin(*aff, "0");
		else
			*aff = ft_strjoin(*aff, " ");
	}
	if (s[i] != '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

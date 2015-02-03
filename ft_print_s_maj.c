/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 15:42:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:43:54 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

static int		ft_point_space(char *s, int *i, char **aff, size_t stop)
{
	size_t		j;
	char		*tmp;
	int			test;

	test = 0;
	tmp = ft_strnew(13);
	j = 0;
	if (s[i[6]--] == '.')
	{
		test = 1;
		while (s[i[6]] >= '0' && s[i[6]] <= '9')
			tmp[j++] = s[i[6]--];
		j = ft_atoi(ft_revers(tmp));
		if (j == 15 && stop == 2)
			(j = 13);
		if (i[4] == 0 && s[i[6] + 1] != '0' && (test = j))
			while (j--)
				ft_putstr(" ");
		else
			while (j-- >= stop)
				(s[i[6] + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
					: (*aff = ft_strjoin(*aff, " "));
	}
	if (s[i[6] + 1] == '0')
		return (-2);
	return (test);
}

static int		ft_suite(int *c, char *tmp, int test, char s)
{
	if (test == 0)
	{
		c[0] = 0;
		ft_putstr(tmp);
		c[0] += ft_strlen(tmp);
		return (c[0]);
	}
	if (test == 1)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (test == 2)
	{
		while (c[4] > c[0])
		{
			(s == '0') ? ft_putstr("0")
				: ft_putstr(" ");
			c[0] += 2;
		}
		return (c[0]);
	}
	return (0);
}

static int		ft_suite_1(int *c, int test, char *s)
{
	if (test == 0)
	{
		while (c[4] > c[0])
		{
			ft_putstr(" ");
			c[0]++;
		}
		return (c[0]);
	}
	if (test == 1)
	{
		if (s[c[2]] != '%')
			c[0] = ft_suite_1(c, 0, s);
		if (c[1] == 0 && s[c[2]] == '%' && c[4] > 0)
			c[0] = c[4];
		return (c[0]);
	}
	return (0);
}

static int		ft_suite_2(int *c, char *s, int test, char *tmp)
{
	if (test == 0)
	{
		if (c[1] == 0 && s[c[2]] == '%' && c[4] > 0)
			c[0] = ft_suite(c, tmp, 2, c[5]);
		c[0] = ft_suite(c, tmp, 0, c[5]);
		return (c[0]);
	}
	if (test == 1)
	{
		tmp = ft_revers(tmp);
		c[4] = ft_atoi(tmp);
		return (c[4]);
	}
	return (0);
}

int				ft_print_s_maj(wchar_t *s1, char *s, int i)
{
	char		*tmp;
	int			c[7];

	c[4] = 0;
	c[0] = i;
	if ((tmp = ft_strnew(13)) && s[--i] == '.')
		c[1] = 1;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[c[4]++] = s[i--];
	c[5] = tmp[c[4] - 1];
	c[4] = ft_suite_2(c, s, 1, tmp);
	c[2] = i;
	if (s[i] == '%')
		i = c[0];
	if (!s1)
		return (ft_suite(c, tmp, 1, s[i + 1]));
	c[3] = 0;
	c[0] = 0;
	c[6] = i;
	while (s1[c[0]] && c[3] <= c[4] && (tmp = ft_strnew(13)))
		c[3] += ft_calc_wstr(s1[c[0]++], c[4], tmp);
	if ((c[1] = ft_point_space(s, c, &tmp, c[0])) == -2)
		return (ft_suite(c, tmp, 0, s[i + 1]));
	if (c[1] > 1 && c[4] == 0 && s[i] == '.')
		return (c[1]);
	c[3] = c[0] - 1;
	c[0] = ft_suite_2(c, s, 0, tmp);
	i = 0;
	while (s1[i] && (c[0] += ft_calc_and_print_wchar(s1[i++], tmp)))
		if (i >= c[3] && c[4] > 0 && c[1] == 1)
			return (c[0]);
	return (ft_suite_1(c, 1, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/01 16:52:53 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int		ft_point_space(char *s, int i, char **aff)
{
	size_t		j;
	char		*tmp;
	int			test;

	tmp = ft_strnew(13);
	j = 0;
	test = 0;
	if (s[i--] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		test = j;
		while (j-- > 1)
			(s[i + 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
				: (*aff = ft_strjoin(*aff, "0"));
		if (s[i + 1] != '0')
			return (-2);
	}
	return (test);
}

static int		s_test(char *s, int i, int test, char c)
{
	if ((c == 0 && s[i] != ' ' && s[i + 1] != '0' && test == 0)
		|| (c == 0 && s[i] == '.' && test == 0) || (test == -2))
	{
		if (c != 0)
			ft_putchar (c);
		return (1);
	}
	return (0);
}

static void		precision(char *s, int i, char **aff, int j)
{
	if (s[i + 1] == '0' && (j--))
		*aff = ft_strjoin (*aff, " ");
	while (j-- > 0)
		(s[i + 1] != '0') ? (*aff = ft_strjoin (*aff, " "))
			: (*aff = ft_strjoin (*aff, "0"));
}

static int		print_c(char *tmp, char **aff, char c)
{
	tmp = ft_strnew(2);
	tmp[0] = c;
	*aff = ft_strjoin(*aff, tmp);
	if (c == 0)
		return (1);
	return (0);
}

int				ft_print_c(va_list ap, char *s, int i, char **aff)
{
	char		c;
	char		*tmp;
	int			j;
	int			test;

	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	c = (char)va_arg(ap, int);
	test = ft_point_space(s, i, aff);
	if ((s_test(s, i, test, c)) == 1)
		return (1);
	precision(s, i, aff, j);
	if (s[i] == ' ' && c == 0)
		*aff = ft_strjoin (*aff, " ");
	if (tmp[0] != '\0' || (s[i] == ' ' && c == 0)
		|| (s[i + 1] == '0' && c == 0) || (s[i] == '.' && c == 0))
		return (-2);
	return (print_c(tmp, aff, c));
}

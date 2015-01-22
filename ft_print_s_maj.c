/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 16:20:10 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

static int ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t j;
	char*tmp;
	int test;
	tmp = ft_strnew(13);
	j = 0;
	if (s[i--] == '.')
	{
		test = 1;
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		while (j-- >= stop)
		{
			if (s[i + 1] == '0')
				*aff = ft_strjoin(*aff, "0");
			else
				*aff = ft_strjoin(*aff, " ");
		}
	}
	if (s[i + 1] == '0')
		return (-2);
	if (test == 1)
			return (1);
	return (0);
}


int		ft_print_s_maj(va_list ap, char *s, int i)
{
	wchar_t		*s1;
	char		*tmp;
	size_t		j;
	int			ret;
	size_t		prec;
	int test;

	j = 0;
	test = 0;
	ret = i;
	tmp = ft_strnew(13);
	i--;
	if (s[i] == '.')
		test = 1;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if (s[i] == '%')
		i = ret;
	s1 = va_arg(ap, wchar_t *);
	if (!s1)
	{
		ft_putstr("(null)");
		return (6);
	}
	prec = 0;
	ret = 0;
	tmp = ft_strnew(13);
	while (s1[ret] && prec <= j)
	{
		prec += ft_calc_wstr(s1[ret], j, tmp);
		ret++;
	}
	tmp = ft_strnew(13);
	if ((test = ft_point_space(s, i, &tmp, ret)) == -2)
	{
		ret = 0;
		ft_putstr(tmp);
		ret += ft_strlen(tmp);
		return (ret);
	}
	prec = ret - 1;
	ret = 0;
	ft_putstr(tmp);
	ret += ft_strlen(tmp);
	tmp = ft_strnew(13);
	i = 0;
	while (s1[i])
	{
		ret += ft_calc_and_print_wchar(s1[i], j, tmp);
		i++;
		tmp = ft_strnew(13);
		if (i >= (int)prec && j > 0 && test == 1)
			return (ret);
	}
	while (j > (size_t)ret)
	{
		ft_putstr(" ");
		ret++;
	}
	return (ret);
}

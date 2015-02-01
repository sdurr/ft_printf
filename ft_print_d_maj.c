/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/01 16:40:07 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include <limits.h>

static int	ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t	j;
	char	*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i--] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		while (j-- > stop)
			*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

static void ft_suite(size_t j, long d, char **aff, char s)
{
	if (j < ft_strlen (ft_litoa(d)) && d > 0 && j > 0)
		j = ft_strlen (ft_litoa(d));
	if (s == ' ' && j == 0 && d >= 0)
		*aff = ft_strjoin(*aff, " ");
}

int			ft_print_d_maj(va_list ap, char *s, int i, char **aff)
{
	long	d;
	char	*tmp;
	size_t	j;

	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, long);
	if (d < 0 && d > LONG_MIN && (*aff = ft_strjoin(*aff, "-")))
		d = d * -1;
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_suite(j, d, aff, s[i]);
	ft_point_space(s, i, aff, j);
	while (j-- > (ft_strlen(ft_litoa(d))))
		(s[i] == '.' || s[i + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
			: (*aff = ft_strjoin(*aff, " "));
	if (d == LONG_MIN && (*aff = ft_strjoin(*aff, "-9223372036854775808")))
		return (0);
	*aff = ft_strjoin(*aff, ft_litoa(d));
	return (0);
}

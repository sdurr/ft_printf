/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 17:05:40 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int ft_point_space(long long int d, char *s, int i, char **aff, size_t stop)
{
	size_t j;
	char *tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i] == '.')
	{
		i--;
		while (s[i] >= '0' && s[i] <= '9')
		{
			tmp[j] = s[i];
			i--;
			j++;
		}
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		if (j > stop)
			while (j > (ft_strlen(ft_litoa(d))))
			{
				*aff = ft_strjoin(*aff, " ");
				j--;
				if (j == stop)
					return (0);
			}
	}
	return (0);
}

int	ft_print_d_long_long(va_list ap, char *s, int i, char **aff)
{
	long long int d;
	char *tmp;
	size_t j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp[j] = s[i];
		i--;
		j++;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, long long int);
	if (d < 0 && d > -9223372036854775807)
	{
		*aff = ft_strjoin(*aff, "-");
		d = d * - 1;
	}
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%') || (s[i] == '.' && d == 0))
		return (0);
	if (s[i] == ' ' && j == 0 && d >= 0)
			*aff = ft_strjoin(*aff, " ");
	ft_point_space(d, s, i, aff, j);
	while (j > (ft_strlen(ft_litoa(d))))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin(*aff, "0");
		else
			*aff = ft_strjoin(*aff, " ");
		j--;
	}
	*aff = ft_strjoin(*aff, ft_litoa(d));
	return (0);
}

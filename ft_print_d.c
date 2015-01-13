/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 14:47:37 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int		ft_point_space(int d, char *s, int i, char **aff, size_t stop)
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
		if (s[i] == ' ' || s[i + 1] == '0')
		{
			*aff = ft_strjoin(*aff, " ");
			j--;
		}
		if (j > stop)
			while (j-- > (ft_strlen(ft_itoa(d))))
			{
			if ( s[i + 1] == '0')
			*aff = ft_strjoin(*aff, "0");
			else
				*aff = ft_strjoin(*aff, " ");
			if (j == stop)
				return (0);
			}
	}
	return (0);
}

int				ft_print_d(va_list ap, char *s, int i, char **aff)
{
	int			d;
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	if (s[i] == '*')
		i--;
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, int);
	if ((d < 0 && d > -2147483648 && s[i + 1] == '0')
		|| (d < 0 && d > -2147483648 && s[i] == '.'))
	{
		*aff = ft_strjoin(*aff, "-");
		d = d * - 1;
		if (j > 0 && s[i] != '.')
			j--;
	}
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0 && s[i - 1] == '%'))
		return (0);
	if (s[i] == ' ' && d >= 0)
			*aff = ft_strjoin(*aff, " ");
	ft_point_space(d, s, i, aff, j);
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

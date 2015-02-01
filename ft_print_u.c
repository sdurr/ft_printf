/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/01 16:37:23 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include "limits.h"

static int		ft_point_space(char *s, int i, char **aff, size_t stop)
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
		if (j > stop)
			while (j-- > stop)
				*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

int				ft_print_u(va_list ap, char *s, int i, char **aff)
{
	unsigned int	d;
	char			*tmp;
	unsigned int	j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi((const char *)tmp);
	d = va_arg(ap, unsigned int);
	if ((d == UINT_MAX && (*aff = ft_strjoin(*aff, "4294967295")))
		|| (s[i] == '.' && s[i + 1] == '0') || (d == 0))
	{
		if (d == 0 && s[i] != '.')
			*aff = ft_strjoin (*aff, "0");
		return (0);
	}
	ft_point_space(s, i, aff, j);
	while (j-- > ft_strlen(ft_litoa(d)) && d > 0)
		(s[i] == '.' || s[i + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
			: (*aff = ft_strjoin(*aff, " "));
	*aff = ft_strjoin(*aff, ft_litoa(d));
	return (0);
}

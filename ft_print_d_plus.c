/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:57:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/28 13:44:32 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

static int		ft_point_space(int d, char *s, int i, char **aff)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	while (j-- > (ft_strlen(ft_itoa(d))) + 1)
	{
		*aff = ft_strjoin(*aff, "0");
	}
	return (0);
}

int				ft_print_d_plus(va_list ap, char *s, int i, char **aff)
{
	int			d;

	d = va_arg(ap, int);
	if (d >= 0)
	{
		*aff = ft_strjoin(*aff, "+");
		ft_point_space(d, s, i, aff);
		*aff = ft_strjoin(*aff, ft_itoa(d));
		return (0);
	}
	else
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

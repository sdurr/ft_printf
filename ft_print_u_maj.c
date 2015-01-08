/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/08 15:07:52 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"
#include "limits.h"

static int			ft_point_space(unsigned long int d, char *s, int i, char **aff, size_t stop)
{
	size_t			j;
	char			*tmp;

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
			while (j > (ft_strlen(ft_litoa((long)d))))
			{
				*aff = ft_strjoin(*aff, " ");
				j--;
				if (j == stop)
					return (0);
			}
	}
	return (0);
}

int					ft_print_u_maj(va_list ap, char *s, int i, char **aff)
{
	unsigned long	d;
	char			*tmp;
	size_t			j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i++];
	tmp = ft_revers(tmp);
	j = ft_atoi((const char *)tmp);
	if (s[i] == '.' && s[i + 1] == '0')
		return (0);
	d = va_arg(ap, unsigned long int);
	if (d == ULONG_MAX)
	{
		*aff = ft_strjoin(*aff, ft_litoa(ULONG_MAX));
		return (0);
	}
	if (d == 0)
	{
		if (s[i] != '.')
			*aff = ft_strjoin (*aff ,"0");
		return (0);
	}
	ft_point_space(d, s, i, aff, j);
	while (j > ft_strlen(ft_litoa(d)) && d > 0)
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

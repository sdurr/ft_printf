/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_long_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 19:19:27 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"
#include <limits.h>

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
		while (j-- > stop)
			*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

int				ft_print_d_long_long(va_list ap, char *s, int i, char **aff)
{
	long long int	d;
	char			*tmp;
	size_t			j;

	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, long long int);
	if (d == LLONG_MIN && (*aff = ft_strjoin(*aff, "-9223372036854775808")))
		return (0);
	if (d < 0 && d > -9223372036854775807 && (*aff = ft_strjoin(*aff, "-")))
		d = d * -1;
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0))
		return (0);
	if (s[i] == ' ' && j == 0 && d >= 0)
		*aff = ft_strjoin(*aff, " ");
	ft_point_space(s, i, aff, j);
	while (j-- > (ft_strlen(ft_litoa(d))))
		(s[i] == '.' || s[i + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
			: (*aff = ft_strjoin(*aff, " "));
	*aff = ft_strjoin(*aff, ft_litoa(d));
	return (0);
}

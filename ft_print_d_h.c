/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/22 19:23:16 by getrembl         ###   ########.fr       */
=======
/*   Updated: 2015/01/26 11:18:43 by sdurr            ###   ########.fr       */
>>>>>>> 5fedfb12a0f083662ba9297865fa4cdfbcf4e522
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
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
	if (s[i] == ' ')
		return (1);
	return (0);
}

int				ft_print_d_h(va_list ap, char *s, int i, char **aff)
{
	int			d;
	char		*tmp;
	size_t		j;
	int			test;

	test = 0;
	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		if (s[i] == 'h' && s[i - 1] == 'h')
		{
			test = 1;
			i--;
		}
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, int);
	if (test == 1)
		d = ft_max_plus_ascii(d);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0))
		return (0);
	if (s[i] == ' ' && j == 0 && d >= 0)
		*aff = ft_strjoin(*aff, " ");
	if ((ft_point_space(s, i, aff, j)) == 1)
		*aff = ft_strjoin(*aff, " ");
	if (s[i] == '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	while (j-- > (ft_strlen(ft_itoa(d))))
		(s[i] == '.' || s[i + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
			: (*aff = ft_strjoin(*aff, " "));
	if (s[i] != '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

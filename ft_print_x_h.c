/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:48:42 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

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

static int		ft_number_befor(char *s1, char *s, int i, char **aff)
{
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_point_space(s, i, aff, j);
	while (j-- > ft_strlen(s1))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin (*aff, "0");
		else
			*aff = ft_strjoin (*aff, " ");
	}
	return (0);
}

int				ft_print_x_h(va_list ap, char *s, int j, char **aff)
{
	char			*hexa;
	unsigned int	q;

	q = va_arg(ap, unsigned int);
	if (s[j - 1] == 'h' && s[j - 2] == 'h')
		q = ft_max_plus(q);
	if ((q == 0 && s[j - 1] == '.') || (q == 0 && s[j - 1] == '0'))
		return (0);
	if (q == 0)
	{
		if (s[j - 1] != '0' && s[j - 1] != '.')
			*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	hexa = ft_strnew(9);
	hexa = ft_op_base_16(hexa, 0, &q);
	hexa = ft_revers(hexa);
	q = ft_number_befor(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0x");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

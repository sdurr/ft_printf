/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 22:44:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/21 14:03:38 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>
#include <limits.h>

static int		ft_point_space(size_t stop, char *s, int i, char **aff)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i] == '.')
	{
		i--;
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
	char			*tmp;
	size_t			j;

	j = 0;
	tmp = ft_strnew(40);
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_point_space(j, s, i, aff);
	while (j-- > ft_strlen(s1))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin (*aff, "0");
		else
			*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

static int		ft_print_o_neg_long(long int d, char *s, int j, char **aff)
{
	unsigned long	quotient;
	char			*octal;

	octal = ft_strnew(12);
	quotient = ULONG_MAX + d;
	octal = ft_base_8_unsig_long(octal, 0, &quotient);
	quotient = ft_number_befor(octal, s, --j, aff);
	*aff = ft_strjoin(*aff, octal);
	return (0);
}

int				ft_print_o_maj(va_list ap, char *s, int j, char **aff)
{
	char			*octal;
	long long		q;
	int				i;

	q = va_arg(ap, long long);
	i = j;
	while (s[i] != '%')
		i--;
	if ((octal = ft_strnew(12)) && s[i + 1] == '#')
		*aff = ft_strjoin(*aff, "0");
	if (q == (long long)ULONG_MAX
		&& (*aff = ft_strjoin(*aff, "1777777777777777777777")))
		return (0);
	if (q == LONG_MIN && (*aff = ft_strjoin(*aff, "1000000000000000000000")))
		return (0);
	if (q < 0)
		return ((ft_print_o_neg_long(q, s, j, aff)));
	if ((q == 0 && s[j - 1] == '.')
		|| (q == 0 && s[j - 1] == '0' && s[j - 2] == '.')
		|| (q == 0 && (*aff = ft_strjoin(*aff, "0"))))
		return (0);
	octal = ft_op_base_8_long(octal, 0, &q);
	q = ft_number_befor(octal, s, --j, aff);
	*aff = ft_strjoin(*aff, octal);
	return (0);
}

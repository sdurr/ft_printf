/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/12 14:40:47 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "libftprintf.h"

static int		ft_point_space(char *s1, char *s, int i, char **aff, size_t stop)
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
			while (j-- > (ft_strlen(s1)))
			{
				*aff = ft_strjoin(*aff, " ");
				if (j == stop)
					return (0);
			}
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
	ft_point_space(s1, s, i, aff, j);
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
	unsigned int	quotient;
	int				rest;
	int				i;
	char			*ret;

	if (s[j - 1] == 'z')
		return (ft_print_x_size_t(ap, s, j, aff));
	quotient = va_arg(ap, unsigned int);
	if (s[j - 1] == 'h' && s[j - 2] == 'h')
		if (quotient > 255)
			quotient = 127 -255 + (quotient -127) - 1;
	if ((quotient == 0 && s[j - 1] == '.') || (quotient == 0 && s[j - 1] == '0'))
		return (0);
	if (quotient == 0)
	{
		if (s[j - 1] != '0' && s[j - 1] != '.')
			*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	i = 0;
	hexa = ft_strnew(9);
	while (quotient != 0)
	{
		rest = quotient % 16;
		(quotient > 15) ? (quotient /= 16) : (quotient = 0);
		(rest < 10) ? (rest += 48) : (rest += 87);
		hexa[i++] = rest;
	}
	hexa[i--] = '\0';
	ret = ft_strnew(ft_strlen(hexa) + 1);
	rest = 0;
	while (i >= 0)
		ret[rest++] = hexa[i--];
	quotient = ft_number_befor(hexa, s, j, aff);
	if (s[j - 1] == '#' && ret[0] != '0')
		*aff = ft_strjoin(*aff, "0x");
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

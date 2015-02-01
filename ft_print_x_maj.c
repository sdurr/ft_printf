/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/30 09:11:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

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
	while (s[i] > '0' && s[i] <= '9')
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
			*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

static int		ft_print_x_maj_negative(int dec, char *s, int j, char **aff)
{
	unsigned int	quotient;
	char			*hexa;

	quotient = 4294967296 + dec;
	hexa = ft_strnew(9);
	hexa = ft_op_base_16(hexa, 1, &quotient);
	quotient = ft_number_befor(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0X");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

int				ft_print_x_maj(va_list ap, char *s, int j, char **aff)
{
	char	*hexa;
	int		quotient;

	quotient = va_arg(ap, int);
	if (quotient < 0)
		return (ft_print_x_maj_negative(quotient, s, j, aff));
	if ((quotient == 0 && s[j - 1] == '.')
		|| (quotient == 0 && s[j - 1] == '0'))
		return (0);
	if (quotient == 0)
	{
		*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	hexa = ft_strnew(15);
	hexa = ft_op_base_16_int(hexa, 1, &quotient);
	quotient = ft_number_befor(hexa, s, j, aff);
	if (s[j - 1] == '#' && hexa[0] != '0')
		*aff = ft_strjoin(*aff, "0X");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

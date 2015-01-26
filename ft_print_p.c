/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:03:22 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:46:12 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int		ft_number_befor(char *s1, char *s, int i, char **aff)
{
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = ft_strnew(13);
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if (s[i] == '-' && (ft_strcmp(s1, "0x0") == 0))
		*aff = ft_strjoin (*aff, "0x0");
	if ((s[i] == '.' && (ft_strcmp(s1, "0x") == 0)) || s[i + 1] == '0')
		*aff = ft_strjoin (*aff, "0x");
	while (j-- > ft_strlen(s1))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin (*aff, "0");
		else
			*aff = ft_strjoin (*aff, " ");
	}
	if (s[i] == '.' && ft_atoi(tmp) > 0)
		*aff = ft_strjoin (*aff, "00");
	if (s[i] == '-' || s[i] == '.' || s[i + 1] == '0')
		return (-1);
	return (0);
}

static int		ft_print_p_negative(int decimal, char *s, int j, char **aff)
{
	unsigned int	quotient;
	int				i;
	char			*hexa;

	if (s)
		j = j - 1;
	quotient = 4294967296 + decimal;
	hexa = ft_strnew(9);
	i = 0;
	hexa = ft_op_base_16(hexa, 0, &quotient);
	hexa = ft_revers(hexa);
	*aff = ft_strjoin(*aff, "0x7");
	i = ft_strlen(hexa);
	while (i++ < 11)
		*aff = ft_strjoin(*aff, "f");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

static void		test_aff(char *s, char *hexa, int j, char **aff)
{
	if (s[j - 1] != 'l' && ft_strlen(hexa) != 7
		&& s[j - 1] != ' ' && s[j - 1] != '+')
		*aff = ft_strjoin(*aff, "0x7");
	else if (ft_strchr(*aff, 'x') == NULL && ft_strlen(hexa) != 7)
		*aff = ft_strjoin(*aff, "0x");
	else
		*aff = ft_strjoin(*aff, "0x10");
}

int				ft_print_p(va_list ap, char *s, int j, char **aff)
{
	char		*hexa;
	int			quotient;
	int			i;

	quotient = va_arg(ap, int);
	if (quotient < 0)
		return (ft_print_p_negative(quotient, s, j, aff));
	hexa = ft_strnew(9);
	if (quotient == 0 && (i = j))
	{
		while (s[i] != '%')
			i--;
		if (((hexa = "0x0") && s[i + 1] == '.') || s[i + 1] == '0')
			hexa = "0x";
		if ((quotient = ft_number_befor(hexa, s, j - 1, aff)) != -1)
			*aff = ft_strjoin(*aff, "0x0");
		return (0);
	}
	hexa = ft_op_base_16(hexa, 0, (unsigned int *)&quotient);
	hexa = ft_revers(hexa);
	test_aff(s, hexa, j, aff);
	i = ft_strlen(hexa);
	if (i > 7 && s[j - 1] != 'l' && s[j - 1] != ' ' && s[j - 1] != '+')
		while (i++ < 11)
			*aff = ft_strjoin(*aff, "f");
	*aff = ft_strjoin(*aff, hexa);
	return (0);
}

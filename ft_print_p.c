/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/11 10:29:14 by sdurr            ###   ########.fr       */
/*   Updated: 2014/12/29 22:47:45 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
/*
static int ft_point_space(char *d, char *s, int i, char **aff, size_t stop)
{
	size_t j;
	char*tmp;

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
			while (j-- > (ft_strlen(d)))
			{
				*aff = ft_strjoin(*aff, " ");
				if (j == stop)
					return (0);
			}
				*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

*/
static int ft_number_befor(char *s1, char *s, int i, char **aff)
{
	char *tmp;
	size_t j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if (s[i] == '-' && (ft_strcmp(s1, "0x0") == 0))
			*aff = ft_strjoin (*aff, "0x0");
	if (s[i] == '.' && (ft_strcmp(s1, "0x") == 0))
		*aff = ft_strjoin (*aff, "0x");
	while (j > ft_strlen(s1))
	{
		if (s[i] == '.')
			*aff = ft_strjoin (*aff, "0");
		else
			*aff = ft_strjoin (*aff, " ");
			j--;
	}
	if (s[i] == '.' && ft_atoi(tmp) > 0)
		*aff = ft_strjoin (*aff, "00");
		if (s[i] == '-' || s[i] == '.')
		return (-1);
	return (0);
}

static int ft_print_p_negative(int decimal, char *s, int j, char **aff)
{
	unsigned int quotient;
	int rest;
	int i;
	char*ret;
	char*hexa;

		if (s)
		j = j - 1;
	quotient = 4294967296 + decimal;
	hexa = ft_strnew(9);
	i = 0;
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
	*aff = ft_strjoin(*aff, "0x7");
	i = ft_strlen(ret);
	while (i++ < 11)
		*aff = ft_strjoin(*aff, "f");
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

int					ft_print_p(va_list ap, char *s, int j, char **aff)
{
	char			*hexa;
	int				quotient;
	int				rest;
	int				i;
	char			*ret;

	quotient = va_arg(ap, int);
	i = 0;
	ret = ft_strnew(1);
	if (quotient < 0)
		return (ft_print_p_negative(quotient, s, j, aff));
	hexa = ft_strnew(9);
	if (quotient == 0)
	{
		i = j;
		while (s[i] != '%')
			i--;
		/*	if (s[i + 1] == '.')
		{
			*aff = ft_strjoin(*aff, "0x");
			return (0);
		}*/
		ret = "0x0";
		if (s[i + 1] == '.')
			ret = "0x";
		if ((quotient = ft_number_befor(ret, s, j, aff)) == -1)
			return (0);
			*aff = ft_strjoin(*aff, "0x0");
			return (0);
	}
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
	*aff = ft_strjoin(*aff, "0x7");
	i = ft_strlen(ret);
	while (i++ < 11)
		*aff = ft_strjoin(*aff, "f");
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

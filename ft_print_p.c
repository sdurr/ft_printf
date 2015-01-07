/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 08:53:28 by sdurr            ###   ########.fr       */
/*   Updated: 2014/12/29 22:47:45 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int			ft_number_befor(char *s1, char *s, int i, char **aff)
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
	while (j > ft_strlen(s1))
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
	return (0);
}
static int ft_print_p_negative(int decimal, char *s, int j, char **aff)
{
	unsigned int quotient;
	int rest;
	int i;
	char*ret;
	char*hexa;

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
	quotient = ft_number_befor(hexa, s, j, aff);
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
		if (quotient < 0)
			return (ft_print_p_negative(quotient, s, j, aff));
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
	*aff = ft_strjoin(*aff, "0x7");
	i = ft_strlen(ret);
	while (i++ < 11)
		*aff = ft_strjoin(*aff, "f");
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

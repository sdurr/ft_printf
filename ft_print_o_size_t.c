/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 22:44:50 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/09 11:15:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>
#include <limits.h>

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
		{
			tmp[j] = s[i];
			i--;
			j++;
		}
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		if (j > stop)
			while (j > (ft_strlen(s1)))
			{
				*aff = ft_strjoin(*aff, " ");
				j--;
				if (j == stop)
					return (0);
			}
	}
	return (0);
}

static int			ft_number_befor(char *s1, char *s, int i, char **aff)
{
	char			*tmp;
	size_t			j;

	j = 0;
	tmp = ft_strnew(40);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%'))
		return (0);
	ft_point_space(s1, s, i, aff, j);
	while (j > ft_strlen(s1))
	{
		if (s[i] == '.' || s[i + 1] == '0')
			*aff = ft_strjoin (*aff, "0");
		else
			*aff = ft_strjoin(*aff, " ");
		j--;
	}
	return (0);
}

int					ft_print_o_size_t(va_list ap, char *s, int j, char **aff)
{
	char			*octal;
	size_t			quotient;
	int				rest;
	int				i;
	char			*ret;

	quotient = va_arg(ap, size_t);
	i = j;
	while (s[i] != '%')
		i--;
	if (s[i + 1] == '#')
		*aff = ft_strjoin(*aff, "0");
	if (quotient == ULLONG_MAX)
	{
		*aff = ft_strjoin(*aff, "1777777777777777777777");
		return (0);
	}
	if ((quotient == 0 && s[j - 1] == '.')
		|| (quotient == 0 && s[j - 1] == '0' && s[j - 2] == '.'))
		return (0);
	if(quotient == 0)
	{
		*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	octal = ft_strnew(12);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 8;
		(quotient > 7) ? (quotient /= 8) : (quotient = 0);
		rest = rest + 48;
		octal[i++] = rest;
	}
	octal[i--] = '\0';
	ret = ft_strnew(ft_strlen(octal) + 1);
	rest = 0;
	while (i >=0)
		ret[rest++] = octal[i--];
	quotient = ft_number_befor(octal, s, j, aff);
	*aff = 	ft_strjoin(*aff, ret);
	return (0);
}

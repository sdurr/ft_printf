/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:15:03 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/06 15:16:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

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
	while (j > ft_strlen(s1));
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
		return (0);
}

static int			ft_print_b_negative(int decimal, char *s, int j, char **aff)
{
	unsigned int	quotient;
	int				rest;
	int				i;
	char			*bin;
	char			*ret;

	bin = ft_strnew(33);
	quotient = 4294967296 + decimal;
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 2;
		(quotient > 1) ? (quotient /= 2) : (quotient = 0);
		rest = rest + 48;
		bin[i++] = rest;
	}
	bin[i--] = '\0';
	ret = ft_strnew(ft_strlen(bin) + 1);
	rest = 0;
	while (i >= 0)
		ret[rest++] = bin[i--];
	quotient = ft_number_befor(bin, s, j, aff);
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

int					ft_print_b(va_list ap, char *s, int j, char **aff)
{
	char			*bin;
	int				quotient;
	int				rest;
	int				i;
	char			*ret;

	quotient = va_arg(ap, int);
	if (quotient < 0)
		return (ft_print_b_negative(quotient, s, j, aff));
	if (quotient == 0)
	{
		*aff = ft_strjoin(*aff, "0");
		return (0);
	}
	bin = ft_strnew(33);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 2;
		(quotient > 1) ? (quotient /= 2) : (quotient = 0);
		rest = rest + 48;
		bin[i++] = rest;
	}
	bin[i--] = '\0';
	ret = ft_strnew(ft_strlen(bin) + 1);
	rest = 0;
	while (i >= 0)
		ret[rest++] = bin[i--];
	quotient = ft_number_befor(bin, s, j, aff);
	*aff = ft_strjoin(*aff, ret);
	return (0);
}

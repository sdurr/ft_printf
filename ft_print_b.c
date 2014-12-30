/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:15:03 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/30 17:07:15 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int			ft_print_b_negative(int decimal)
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
	ft_putstr(ret);
	return (ft_strlen(bin));
}

int					ft_print_b(va_list ap)
{
	char			*bin;
	int				quotient;
	int				rest;
	int				i;
	char			*ret;

	quotient = va_arg(ap, int);
	if (quotient < 0)
		return (ft_print_b_negative(quotient));
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
	ft_putstr(ret);
	return (ft_strlen(bin));
}

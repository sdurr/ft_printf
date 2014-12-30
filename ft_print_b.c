/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:15:03 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/30 15:44:11 by getrembl         ###   ########.fr       */
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
	quotient = 4 294 967 295 + 1 - decimal;
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

	bin = ft_strnew(33);
	quotient = va_arg(ap, int);
	i = 0;
	if (quotient < 0)
		ft_print_b_negative(quotient);
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

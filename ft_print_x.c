/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/30 17:08:51 by getrembl         ###   ########.fr       */
/*   Updated: 2014/12/29 22:47:45 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_print_x_negative(int decimal)
{
	unsigned int	quotient;
	int				rest;
	int				i;
	char			*ret;
	char			*hexa;

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
	ft_putstr(ret);
	return (ft_strlen(hexa));
}

int			ft_print_x(va_list ap)
{
	char	*hexa;
	int		quotient;
	int		rest;
	int		i;
	char	*ret;

	quotient = va_arg(ap, int);
	if (quotient < 0)
		return (ft_print_x_negative(quotient));
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
	ft_putstr(ret);
	return (ft_strlen(hexa));
}


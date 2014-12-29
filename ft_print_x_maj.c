/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 19:05:38 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int		ft_print_x_maj(va_list ap)
{
	char	*hexa;
	int		quotient;
	int		rest;
	int		i;
	char	*ret;

	hexa = ft_strnew(100);
	quotient = va_arg(ap, int);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 16;
		(quotient > 15) ? (quotient = quotient / 16) : (quotient = 0);
		(rest < 10) ? (rest = 48 + rest) : (rest = 55 + rest);
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


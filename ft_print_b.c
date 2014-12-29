/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 21:15:03 by getrembl          #+#    #+#             */
/*   Updated: 2014/12/29 22:19:18 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_print_b(va_list ap)
{
	char	*bin;
	int		quotient;
	int		rest;
	int		i;
	char	*ret;

	bin = ft_strnew(33);
	quotient = va_arg(ap, int);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 2;
		(quotient > 1) ? (quotient = quotient / 2) : (quotient = 0);
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

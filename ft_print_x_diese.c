/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 12:10:23 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 15:29:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int		ft_print_x_diese(va_list ap)
{
	char	hexadec[100];
	int		quotient;
	int		tmp;
	int		i;

	quotient = va_arg(ap, int);
	i = 0;
	while (quotient != 0)
	{
		(quotient > 15) ? (tmp = quotient % 16)	: (tmp = quotient);
		(quotient > 15) ? (quotient = quotient % 16) : (quotient = 0);
		(tmp < 10) ? (tmp = 80 + tmp) : (tmp = 87 + tmp);
		hexadec[i++] = tmp;
	}
	hexadec[i] = '\0';
	ft_putstr("0x");
	ft_putstr(hexadec);
	return (ft_strlen(hexadec));
}


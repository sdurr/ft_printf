/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:57:27 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/30 14:03:48 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "libftprintf.h"

int		ft_print_d_plus(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	if (d >= 0)
	{
	ft_putchar('+');
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)) + 1);
	}
	else
		ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

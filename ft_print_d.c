/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 15:25:25 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_d(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 15:26:53 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_u(va_list ap)
{
	unsigned int d;

	d = va_arg(ap, unsigned int);
	ft_putnbr(d);
	return (ft_strlen(ft_itoa(d)));
}

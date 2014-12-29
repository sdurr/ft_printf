/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 19:58:39 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap)
{
	if ((s[i - 1] == '+' && s[i] == 'd') || (s[i - 1] == '+' && s[i] == 'i'))
	{
		ft_putchar('+');
		return (ft_print_d(ap) + 1);
	}
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_print_d(ap));
		if (s[i] == 'u')
		return (ft_print_d(ap));
	if (s[i] == 's')
		return (ft_print_s(ap));
	if (s[i] == 'c')
		return (ft_print_c(ap));
	if (s[i] == '%')
	{
		ft_putchar ('%');
		return (1);
	}
	if (s[i] == 'x' && s[i - 1] == '#')
	{
		ft_putstr("0x");
		return (ft_print_x(ap));
	}
	if (s[i] == 'x')
		return (ft_print_x(ap));
	if (s[i] == 'X')
		return (ft_print_x_maj(ap));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 15:03:12 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap)
{
	int c;

	c = 0;
	if (s[i] == '#')
	{
		c = 1;
		i++;
	}
	if ((s[i] == '+' && s[i + 1] == 'd') || (s[i] == '+' && s[i + 1] == 'i'))
	{
		ft_putchar('+');
		return (ft_print_d(ap));
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
	if (s[i] == 'x' && c == 1)
		return (ft_print_x_diese(ap));
	if (s[i] == 'x' && c == 0)
		return (ft_print_x(ap));
	return (0);
}

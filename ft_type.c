/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/05 16:13:21 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap)
{
	if ((s[i - 1] == '+' && s[i] == 'd') || (s[i - 1] == '+' && s[i] == 'i'))
	{
		return (ft_print_d_plus(ap));
	}

	if (s[i -1] == 'l' && s[i] == 'd')
		return (ft_print_d_long(ap));
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_print_d(ap, s, i));
	if (s[i] == 'o' && s[i - 1] == '#')
	{
		ft_putchar('0');
		return (ft_print_o(ap, s, i) + 1);
	}
	if (s[i] == 'u')
		return (ft_print_u(ap, s, i));
	if (s[i] == 'o')
		return (ft_print_o(ap, s, i));
	if (s[i] == 's')
		return (ft_print_s(ap, s, i));
	if (s[i] == 'b')
		return (ft_print_b(ap, s, i));
	if (s[i] == 'c')
		return (ft_print_c(ap, s, i));
		if (s[i] == 'C')
		return (ft_print_c_maj(ap, s, i));
	if (s[i] == '%')
	{
		ft_putchar ('%');
		return (1);
	}
	if ((s[i] == 'x' && s[i - 1] == '#') || (s[i] == 'X' && s[i - 1] == '#'))
	{
		if (s[i] == 'x')
		{
			ft_putstr("0x");
			return (ft_print_x(ap, s, i) + 2);
		}
		else
			ft_putstr("0X");
		return (ft_print_x_maj(ap, s, i) + 2);
	}
	if (s[i] == 'x')
		return (ft_print_x(ap, s, i));
	if (s[i] == 'X')
		return (ft_print_x_maj(ap, s, i));
	return (0);
}

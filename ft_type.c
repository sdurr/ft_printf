/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 17:41:29 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap, char **aff)
{
	if ((s[i - 1] == '+' && s[i] == 'd') || (s[i - 1] == '+' && s[i] == 'i'))
	{
		return (ft_print_d_plus(ap, aff));
	}

	if (s[i -1] == 'l' && s[i] == 'd')
		return (ft_print_d_long(ap, aff));
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_print_d(ap, s, i, aff));
	if (s[i] == 'o' && s[i - 1] == '#')
	{
		*aff = ft_strjoin(*aff, "0");
		return (ft_print_o(ap, s, i, aff));
	}
	if (s[i] == 'u')
		return (ft_print_u(ap, s, i, aff));
	if (s[i] == 'o')
		return (ft_print_o(ap, s, i, aff));
	if (s[i] == 's')
		return (ft_print_s(ap, s, i, aff));
		if (s[i] == 'b')
		return (ft_print_b(ap, s, i, aff));
	if (s[i] == 'p')
		return (ft_print_p(ap, s, i, aff));
	if (s[i] == 'c')
		return (ft_print_c(ap, s, i, aff));
	if (s[i] == '%')
	{
		*aff = ft_strjoin(*aff, "%");
		return (1);
	}
	if (s[i] == 'x')
		return (ft_print_x(ap, s, i, aff));
	if (s[i] == 'X')
		return (ft_print_x_maj(ap, s, i, aff));
	return (0);
}

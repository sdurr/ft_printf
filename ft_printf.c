/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/28 15:23:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdarg.h>
#include "libft.h"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	char	*s;
	int		d;

	s = ft_strdup(format);
	i = 0;
	ret = 0;
	va_start(ap, format);
	if (ft_test_type(s) == -1)
		return (0);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			if (s[i] == '#' && s[i - 1] == '%')
				i++;
			if (s[i] == 'x' && s[i - 1] == '#')
				i++;
			ft_putchar(s[i]);
			ret++;
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			d = ft_type(s, i, ap);
			ret = ret + d;
		}
		i++;
	}
	va_end(ap);
	ft_putnbr(ret);
	return (ret);
}

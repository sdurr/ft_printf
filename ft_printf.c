/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/05 15:45:25 by sdurr            ###   ########.fr       */
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

	s = ft_strdup(format);
	i = 0;
	ret = 0;
	va_start(ap, format);

	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
				ft_putchar(s[i++]);
			ret++;
		}
		if (s[i++] == '%')
		{
			if(s[i] == '#' || s[i] == '+' || s[i] == 'l')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			ret = ret + ft_type(s, i, ap);
		}
			i++;
	}
	va_end(ap);
	return (ret);
}

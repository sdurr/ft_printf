/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 17:33:49 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdarg.h>
#include "libft.h"

static int ft_flags_diese(int i, char *s)
{
	i++;
	if (s[i] == 'x' && s[i - 1] == '#')
		i++;
	if (s[i] == 'c' && s[i - 1] == '#')
		i++;
	if (s[i] == 'd' && s[i - 1] == '#')
		i++;
	if (s[i] == 's' && s[i - 1] == '#')
		i++;
	if (s[i] == 'i' && s[i - 1] == '#')
		i++;
	if (s[i] == 'u' && s[i - 1] == '#')
		i++;
	return (i);
}

static int ft_flags_plus(int i, char *s)
{
	i++;
	if (s[i] == 'd' && s[i - 1] == '+')
		i++;
	if (s[i] == 'i' && s[i - 1] == '+')
		i++;
	return (i);
}

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
	if (ft_test_type(s) == -1)
		return (0);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			if (s[i - 1] == '#' && s[i - 2] == '%')
				i = ft_flags_diese(i, s);
			if (s[i - 1] == '+' && s[i - 2] == '%')
				i = ft_flags_plus(i, s);
			ft_putchar(s[i++]);
			ret++;
		}
		if (s[i++] == '%')
			ret = ret + ft_type(s, i, ap);
		i++;
	}
	va_end(ap);
	return (ret);
}

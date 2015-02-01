/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/28 13:35:08 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdarg.h>

int				ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	char	*s;
	char	*aff;
	char	*tmp;
	int		ret;
	int		test;

	s = ft_strdup(format);
	i = -1;
	ret = 0;
	va_start(ap, format);
	tmp = ft_strnew(2);
	while (s[++i])
	{
		aff = ft_strnew(1);
		while (s[i] != '%' && s[i] && (tmp[0] = s[i++]))
			aff = ft_strjoin(aff, tmp);
		ft_putstr(aff);
		ret += ft_strlen(aff);
		aff = ft_strnew(1);
		if (s[i++] == '%')
		{
			while ((s[i] >= '0' && s[i] <= '9') || s[i] == '#' || s[i] == '+'
				   || s[i] == 'l' || s[i] == ' ' || s[i] == '.' || s[i] == '-'
				   || s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
				i++;
			if ((test = ft_type(s, i, ap, &aff)) == -1)
				i--;
			if (test > 0 && test != -2)
				ret = test + ret;
		}
		if (test == -2)
		{
			ret += ft_strlen(aff);
			if ((aff = ft_strchr(aff, '0')) != NULL)
				ft_putstr(aff);
			if (s[i - 1] == '.')
				ret += 1;
			while (s[++i])
				ret += 1;
			return (ret);
		}
		ft_putstr(aff);
		ret += ft_strlen(aff);
	}
	return (ret);
}

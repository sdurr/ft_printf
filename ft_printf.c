/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/08 12:09:07 by sdurr            ###   ########.fr       */
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
	char	*s;
	char *aff;
	char *tmp;
	int ret;
	int test;
	aff = ft_strnew(1);
	s = ft_strdup(format);
	i = 0;
	ret = 0;
	va_start(ap, format);
	tmp = ft_strnew(2);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			tmp[0] = s[i];
			aff = ft_strjoin(aff, tmp);
			i++;
		}
		if (s[i++] == '%')
		{

				while ((s[i] >= '0' && s[i] <= '9') || s[i] == '#' || s[i] == '+' || s[i] == 'l' || s[i] == ' ' || s[i] == '.' || s[i] == '-' || s[i] == 'h' || s[i] == '*' || s[i] == 'j' || s[i] == 'z')
				i++;
				if ((test = ft_type(s, i, ap, &aff)) == -1)
					return (-1);
				ret = test + ret;
		}
		i++;
	}
	ft_putstr(aff);
	va_end(ap);
	return (ft_strlen(aff) + ret);
}

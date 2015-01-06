/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 15:26:28 by sdurr            ###   ########.fr       */
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
			if(s[i] == '#' || s[i] == '+' || s[i] == 'l')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			ret = ret + ft_type(s, i, ap, &aff);
//			return (0);
		}
		i++;
	}
	ft_putstr(aff);
	va_end(ap);
	return (ft_strlen(aff) + ret);
}

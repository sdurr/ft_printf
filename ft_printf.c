/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 13:03:21 by sdurr            ###   ########.fr       */
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
	char *aff;
	char *tmp;
	aff = ft_strnew(1);
	s = ft_strdup(format);
	i = 0;
	ret = 0;
	va_start(ap, format);
	tmp = ft_strnew(2);
//	if (ft_test_type(s) == -1)
	//	return (-1);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			tmp[0] = s[i];
			aff = ft_strjoin(aff, tmp);
			i++;
			ret++;
		}
		if (s[i++] == '%')
		{
			if(s[i] == '#' || s[i] == '+' || s[i] == 'l')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			ret = ret + ft_type(s, i, ap, &aff);
		}
			i++;
	}
	ft_putstr(aff);
	va_end(ap);
	return (ret);
}

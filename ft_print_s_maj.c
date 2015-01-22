/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 09:05:48 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

int		ft_print_s_maj(va_list ap, char *s, int i)
{
	wchar_t		*s1;
	char		*tmp;
	size_t		j;
	int			ret;

	j = 0;
	ret = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
 	s1 = va_arg(ap, wchar_t *);
	if (!s1)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (*s1)
	{
		ret += ft_calc_and_print_wchar(*s1, j, tmp);
		s1++;
		tmp = ft_strnew(13);
		j = 0;
	}
	return (ret);
}

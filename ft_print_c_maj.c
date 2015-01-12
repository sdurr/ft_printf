/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/10 19:03:12 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"

int				ft_print_c_maj(va_list ap, char *s, int i)
{
	wchar_t		c;
	char		*tmp;
	int			j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	c = va_arg(ap, wchar_t);
	while (j-- > 1)
		ft_putchar (' ');
	if (c > 0 && c < 128)
		ft_putchar((char)c);
	else if (c > 127 && c < 65535)
		ft_putwchar(c);
	else
		return (1);
	return (1);
}

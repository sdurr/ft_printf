/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/12 18:05:20 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
/*
static int		ft_dectobin(wchar_t c)
{
	return (0);
}

static wchar_t	*itow(unsigned long val)
{
	static wchar_t buf[30];
	wchar_t *wcp = &buf[29];
	*wcp = L'\0';
	while (val != 0)
	{
		*--wcp = btowc ('0' + val % 10);
		val /= 10;
	}
	if (wcp == &buf[29])
		*--wcp = L'0';
	return wcp;
}
*/
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
	c = (wchar_t)va_arg(ap, unsigned int);
	while (j-- > 1)
		ft_putchar (' ');
	if (c >= 0x0000 && c <= 0x007F)
		ft_putchar((char)c);
	if (c >= 0x0080 && c <= 0x1F8FF)
		ft_putwchar(c);
	else
		return (1);
	return (1);
}

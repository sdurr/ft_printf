/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 13:59:17 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"

static unsigned int	ft_dectobin(unsigned int dec)
{
	char			*bin;
	char			*tmp_ret;
	unsigned int	quotient;
	unsigned int	rest;
	unsigned int	i;

	bin = ft_strnew(33);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient & 1;
		(quotient > 1) ? (quotient = quotient >> 1) : (quotient = 0);
		rest = rest + 48;
		bin[i++] = rest;
	}
	bin[i--] = '\0';
	tmp_ret = ft_strnew(ft_strlen(bin) + 1);
	rest = 0;
	while (i >= 0)
		ret[rest++] = bin[i--];
	i = ft_atoui(ret);
	return (i);
}

/*
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
int					ft_print_c_maj(va_list ap, char *s, int i)
{
	wchar_t			wc;
	unsigned int	i;
	unsigned int	digit;

	wc = (wchar_t)va_arg(ap, unsigned int);
	i = (unsigned int)wc;
	i = ft_dectobin(i);
	digit = ft_nbdigit(i);
	if (digit < 8)
	{
		ft_putchar((char)c);
		return (1);
	}
	if (digit > 7 && digit < 12)
		ft_putwchar(wc, 2);
	if (digit > 11 && digit < 17)
		ft_putwchar(wc, 3);
	else
		ft_putwchar(wc, 4);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/15 16:15:45 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"

static int			ft_point_space(char *s, int i, char **aff)
{
	size_t			j;
	char			*tmp;
	int				test;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i] == '.')
	{
		i--;
		while (s[i] >= '0' && s[i] <= '9')
		{
			tmp[j] = s[i];
			i--;
			j++;
		}
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		test = j;
		while (j-- > 1)
		{
			if (s[i + 1] != '0')
				*aff = ft_strjoin(*aff, " ");
			else
				*aff = ft_strjoin(*aff, "0");
		}
	}
	return (test);
}
/*
static char			*ft_wcinmask(char *mask, char *wc)
{
	int				i;
	int				j;

	i = ft_strlen(mask);
	j = ft_strlen(wc);
	while (i > 0)
	{
		if (mask[i] == 'x')
		{
			mask[i] = wc[j];
			i--;
		}
		if (mask[i] != 'x')
			i--;
		j--;
	}
	while (mask[i] == 'x')
	{
		mask[i] = '0';
		i--;
	}
	return (mask);
}

static unsigned int ft_unimask(unsigned int bin, unsigned int digit)
{
	char			*mask_2;
	char			*mask_3;
	char			*mask_4;
	char			*wc;

	mask_2 = "110xxxxx10xxxxxx";
	mask_3 = "1110xxxx10xxxxxx10xxxxxx";
	mask_4 = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	wc = ft_uitoa(bin);
	if (digit >= 8 && digit <= 11)
		wc = ft_wcinmask(mask_2, wc);
	if (digit >= 12 && digit <= 16)
		wc = ft_wcinmask(mask_3, wc);
	if (digit >= 17 && digit <= 21)
		wc = ft_wcinmask(mask_4, wc);
	bin = ft_atoui(wc);
	return (bin);
}
*/
static unsigned int	ft_dectobin(unsigned int dec)
{
	char			*bin;
	char			*tmp_ret;
	unsigned int	quotient;
	unsigned int	rest;
	unsigned int	i;

	quotient = dec;
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
	while (i)
		tmp_ret[rest++] = bin[i--];
	i = ft_atoui(tmp_ret);
	return (i);
}

int					ft_print_c_maj(va_list ap, char *s, int i, char **aff)
{
	wchar_t			wc;
	unsigned int	k;
	unsigned int	digit;
//
	char *tmp;
	int j;
	int test;
//
	wc = (unsigned int)va_arg(ap, wchar_t);
//
	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	test = ft_point_space(s, i, aff);
	if ((wc == 0 && j == 0 && s[i] != ' ' && s[i + 1] != '0' && test == 0)
		|| (wc == 0 && s[i] == '.' && j == 0 && test == 0) || (wc == 0 && s[i] == '+'))
		return (1);
	if (s[i + 1] == '0')
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
	while (j-- > 0)
	{
		if (s[i + 1] != '0')
			*aff = ft_strjoin (*aff, " ");
		else
			*aff = ft_strjoin (*aff, "0");
	}
	if (s[i] == ' ' && wc == 0)
		*aff = ft_strjoin (*aff, " ");
	if (tmp[0] != '\0' || (s[i] == ' ' && wc == 0)
		|| (s[i + 1] == '0' && wc == 0) || (s[i] == '.' && wc == 0))
		return (-2);
	if (wc == 0)
		return (1);
//
	k = (unsigned int)wc;
	k = ft_dectobin(k);
	digit = ft_nbudigit(k);
	if (digit < 8)
	{
		ft_putchar((char)wc);
		return (1);
	}
/*	wc = ft_unimask(k, digit);
	if (digit > 7 && digit < 12)
		ft_putwchar(wc, 2);
	if (digit > 11 && digit < 17)
		ft_putwchar(wc, 3);
	else
		ft_putwchar(wc, 4);
*/	return (1);
}

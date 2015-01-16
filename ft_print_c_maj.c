/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/16 13:08:18 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

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

static char			*ft_unimask(char *bin, size_t digit)
{
	char			*mask_2;
	char			*mask_3;
	char			*mask_4;

	mask_2 = ft_strdup("110xxxxx10xxxxxx");
	mask_3 = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	mask_4 = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	if (digit >= 8 && digit <= 11)
		bin = ft_wcinmask(mask_2, bin);
	if (digit >= 12 && digit <= 16)
		bin = ft_wcinmask(mask_3, bin);
	if (digit >= 17 && digit <= 21)
		bin = ft_wcinmask(mask_4, bin);
	return (bin);
}


static char 	*ft_dectobin(unsigned int dec)
{
	char			*bin;
	unsigned int	quotient;
	unsigned int	rest;
	unsigned int	i;

	quotient = dec;
	bin = ft_strnew(33);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 2;
		(quotient > 1) ? (quotient = quotient / 2) : (quotient = 0);
		rest = rest + 48;
		bin[i++] = rest;
	}
	bin[i--] = '\0';
	bin = ft_revers(bin);
	return (bin);
}

static unsigned int		*ft_otoc(char *s, unsigned int nbyte)
{
	unsigned int		*ret;
	char				*bkp;
	size_t				i_s;
	size_t				i_bkp;
	size_t				i_ret;

	bkp = ft_strnew((ft_strlen(s) /nbyte) + 1);
	ret =  malloc(sizeof(int) * nbyte + 1);
	i_s = 0;
	i_ret = 0;
	while (s[i_s])
	{
		i_bkp = 0;
		while (i_bkp < 8)
			bkp[i_bkp++] = s[i_s++];
		bkp[i_bkp] = '\0';
		ret[i_ret++] = ft_atoull(bkp);
	}
	return (ret);
}

static unsigned int		*ft_split(char *s)
{
	unsigned int		nb;

	nb = 0;
	if (ft_strlen(s) > 8 && ft_strlen(s) <= 16)
		nb = 2;
	else if (ft_strlen(s) > 16 && ft_strlen(s) <= 24)
		nb = 3;
	else
		nb = 4;
	return (ft_otoc(s, nb));
}

int					ft_print_c_maj(va_list ap, char *s, int i, char **aff)
{
	unsigned int	wc;
	unsigned int	*k;
//	unsigned int	digit;
//
	char *tmp;
	int j;
	int test;
//
	wc = va_arg(ap, unsigned int);
//
	ft_putstr("wc=");
	ft_putnbr(wc);
	ft_putchar('\n');
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

	if (wc <= 127)
	{
		ft_putchar((char)wc);
		return (1);
	}
//	ft_putnbr(wc);
	//ft_putchar('\n');
	tmp = ft_dectobin(wc);
//	digit = ft_nbudigit(tmp);
//	ft_putnbr(digit);
//	ft_putchar('\n');

	tmp = ft_unimask(tmp, ft_strlen(tmp));
	k = ft_split(tmp);
	ft_putchar('\n');
	ft_putstr("k[0] =");
	ft_putnbr(k[0]);
	return (1);
}

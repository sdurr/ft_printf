/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/21 15:35:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

int		ft_print_s_maj(va_list ap, char *s, int i)
{
	wchar_t		*tmp1;
	wchar_t		*s1;
	char		*tmp;
	size_t		j;
	int			ret;
	unsigned int *k;


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
	tmp1 = s1;
	while (*tmp1 != '\0')
	{
		i++;
		tmp1++;
	}
	k = malloc(sizeof(int) * i + 1);
	i = 0;
	tmp1 = s1;
	while (*tmp1 != '\0')
	{
		ft_putchar ('\n');
		ft_putstr("k[i] = ");
		k[i]= (unsigned int)*tmp1;
		ft_putnbr(k[i]);
		ft_putchar ('\n');
		tmp1++;
		i++;
	}
	i = 0;
	while (k[i] > 0)
	{
		ft_putnbr(k[i]);
		ret += ft_calc_and_print_wchar(k[i], j, tmp);
		i++;
		tmp = ft_strnew(13);
		j = 0;
		ft_putnbr(k[i]);
	}
	return (ret);
}

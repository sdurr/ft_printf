/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_s_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:00:04 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 11:10:29 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

static int		ft_suite_1(int *c, int test, char *s)
{
	if (test == 0)
	{
		while (c[4] > c[0])
		{
			ft_putstr(" ");
			c[0]++;
		}
		return (c[0]);
	}
	if (test == 1)
	{
		if (s[c[2]] != '%')
			c[0] = ft_suite_1(c, 0, s);
		if (c[1] == 0 && s[c[2]] == '%' && c[4] > 0)
			c[0] = c[4];
		return (c[0]);
	}
	return (0);
}

static int		ft_return_s_maj(char *s, int *c, wchar_t *s1, char *tmp)
{
	int j;

	j = 0;
	c[3] = c[0] - 1;
	c[0] = ft_suite_2(c, s, 0, tmp);
	while (s1[j] && (c[0] += ft_calc_and_print_wchar(s1[j++], tmp)))
		if (j >= c[3] && c[4] > 0 && c[1] == 1)
			return (c[0]);
	return (ft_suite_1(c, 1, s));
}

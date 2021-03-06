/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suite_s_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:12:01 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 11:15:42 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_suite_s_maj(int *c, int test, char *s)
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
			c[0] = ft_suite_s_maj(c, 0, s);
		if (c[1] == 0 && s[c[2]] == '%' && c[4] > 0)
			c[0] = c[4];
		return (c[0]);
	}
	return (0);
}

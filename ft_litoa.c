/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:11:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:59:45 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "limits.h"

char	*ft_litoa(long n)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_longlen(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		ret[i++] = '-';
		if (n < LONG_MIN)
			return ("-2147483648");
		n *= -1;
	}
	while (n >= 10 && n <= LONG_MAX)
	{
		ret[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 10)
		ret[i++] = n + '0';
	ret[i] = '\0';
	ret = ft_revers(ret);
	return (ret);
}

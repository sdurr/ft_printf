/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:11:27 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 20:52:26 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "libftprintf.h"

char	*ft_litoa(long n)
{
	char	*ret;
	long		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_long_long(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		ret[i++] = '-';
		n = n * -1;
	}
	while (n >= 10 && n <= 2147483647)
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

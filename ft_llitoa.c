/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:14:24 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/13 18:14:14 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdlib.h>
#include <limits.h>

char		*ft_llitoa(long long ll)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * ft_llonglen(ll) + 1)))
		return (NULL);
	if (ll < 0)
	{
		ret[i++] = '-';
		if (ll == LONG_LONG_MIN)
			return ("-9223372036854775808");
		ll *= -1;
	}
	while (ll >= 10 && ll <= LONG_LONG_MAX)
	{
		ret[i++] = ll % 10 + '0';
		ll /= 10;
	}
	if (ll < 10)
		ret[i++] = ll + '0';
	ret = ft_revers(ret);
	return (ret);
}

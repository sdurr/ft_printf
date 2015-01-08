/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:16:54 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/08 15:52:10 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include <limits.h>

size_t		ft_llonglen(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll < LONG_LONG_MIN)
		return (20);
	if (ll < 0)
	{
		ret++;
		ll *= -1;
	}
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}

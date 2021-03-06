/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 12:17:27 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/08 15:46:01 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

size_t		ft_longlen(long l)
{
	size_t	ret;

	ret = 1;
	if (l < 0)
	{
		if (l < LONG_MIN)
			return (12);
		ret++;
		l *= -1;
	}
	while ((l /= 10) > 0)
		ret++;
	return (ret);
}

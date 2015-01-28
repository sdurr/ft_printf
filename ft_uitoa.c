/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:02:25 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/24 11:57:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "limits.h"

char				*ft_uitoa(unsigned int n)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_longlen(n) + 1)))
		return (NULL);
	while (n >= 10 && n <= UINT_MAX)
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

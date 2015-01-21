/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_base_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:21:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/21 14:01:14 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_op_base_8_unsigned_int(char *oc, int rest, unsigned int *q)
{
	int		i;

	i = 0;
	oc = ft_strnew(9);
	while (*q != 0)
	{
		rest = *q % 8;
		(*q > 7) ? (*q /= 8) : (*q = 0);
		rest = rest + 48;
		oc[i++] = rest;
	}
	oc[i--] = '\0';
	oc = ft_revers(oc);
	return (oc);
}

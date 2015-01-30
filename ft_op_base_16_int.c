/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_base_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:21:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/30 09:16:32 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_op_base_16_maj(char *hexa, int rest, int *q)
{
	int		i;

	i = 0;
	hexa = ft_strnew(9);
	while (*q != 0)
	{
		rest = *q % 16;
		(*q > 15) ? (*q /= 16) : (*q = 0);
		(rest < 10) ? (rest += 48) : (rest += 55);
		hexa[i++] = rest;
	}
	hexa[i--] = '\0';
	hexa = ft_revers(hexa);
	return (hexa);
}

char			*ft_op_base_16_int(char *hexa, int rest, int *q)
{
	int		i;

	i = 0;
	hexa = ft_strnew(9);
	if (rest == 1)
		return (ft_op_base_16_maj(hexa, 0, q));
	while (*q != 0)
	{
		rest = *q % 16;
		(*q > 15) ? (*q /= 16) : (*q = 0);
		(rest < 10) ? (rest += 48) : (rest += 87);
		hexa[i++] = rest;
	}
	hexa[i--] = '\0';
	hexa = ft_revers(hexa);
	return (hexa);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_base_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:21:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:52:38 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_base_8_unsig_long(char *octal, int rest, unsigned long *q)
{
	int		i;

	i = 0;
	octal = ft_strnew(9);
	while (*q != 0)
	{
		rest = *q % 8;
		(*q > 7) ? (*q /= 8) : (*q = 0);
		rest = rest + 48;
		octal[i++] = rest;
	}
	octal[i--] = '\0';
	octal = ft_revers(octal);
	return (octal);
}

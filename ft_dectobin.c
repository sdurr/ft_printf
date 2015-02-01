/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:50:46 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/01 16:53:29 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*ft_dectobin(unsigned int dec)
{
	char			*bin;
	unsigned int	quotient;
	unsigned int	rest;
	unsigned int	i;

	quotient = dec;
	bin = ft_strnew(33);
	i = 0;
	while (quotient != 0)
	{
		rest = quotient % 2;
		(quotient > 1) ? (quotient /= 2) : (quotient = 0);
		rest = rest + 48;
		bin[i++] = rest;
	}
	bin[i--] = '\0';
	bin = ft_revers(bin);
	return (bin);
}

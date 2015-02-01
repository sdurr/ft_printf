/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:50:46 by sdurr             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/01/22 15:34:25 by getrembl         ###   ########.fr       */
=======
/*   Updated: 2015/01/24 11:55:13 by sdurr            ###   ########.fr       */
>>>>>>> 5fedfb12a0f083662ba9297865fa4cdfbcf4e522
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

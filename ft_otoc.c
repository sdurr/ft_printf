/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:34:26 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/19 14:49:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

unsigned int	*ft_otoc(char *s, unsigned int nbyte)
{
	unsigned int	*ret;
	char			*bkp;
	size_t			i_s;
	size_t			i_bkp;
	size_t			i_ret;

	bkp = ft_strnew((ft_strlen(s) /nbyte) + 1);
	ret =  malloc(sizeof(int) * nbyte + 1);
	i_s = 0;
	i_ret = 0;
	while (i_s <= ft_strlen(s))
	{
		i_bkp = 0;
		while (i_bkp < 8)
			bkp[i_bkp++] = s[i_s++];
		bkp[i_bkp] = '\0';
		ret[i_ret++] = ft_atoull(bkp);
	}
	return (ret);
}

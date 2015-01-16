/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:56:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/16 13:27:57 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long			ft_atoull(const char *str)
{
	unsigned long long		nb;
	unsigned int			i;

	i = 0;
	nb = 0;
	if (str)
	{
		while (str[i] >= 1 && str[i] <= 32)
				i++;
		while (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i++] - '0');
	}
	return (nb);
}

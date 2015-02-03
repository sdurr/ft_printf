/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:43:09 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:22:08 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_atoi(const char *str)
{
	int					nb;
	int					i;
	int					neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str)
	{
		while (str[i] >= 1 && str[i] <= 32)
			i++;
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
D				neg = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
			nb = (nb * 10) + (str[i++] - '0');
	}
	return (nb * neg);
}

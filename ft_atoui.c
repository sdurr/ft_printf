/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:56:59 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/13 13:36:22 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int			ft_atoui(const char *str)
{
	unsigned int		nb;
	unsigned int		i;

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

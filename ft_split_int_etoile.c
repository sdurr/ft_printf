/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int_etoile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:00:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/20 12:31:45 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

unsigned int		*ft_split_int_etoile(char *s)
{
	unsigned int nb;

	nb = 0;
	if (ft_strlen(s) > 8 && ft_strlen(s) <= 16)
		nb = 2;
	else if (ft_strlen(s) > 16 && ft_strlen(s) <= 24)
		nb = 3;
	else
		nb = 4;
	return (ft_otoc(s, nb));
}

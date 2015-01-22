/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_print_wcha.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:12:48 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 14:51:16 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int			ft_calc_wstr(unsigned int wc, int j, char *tmp)
{
	int				i;
	unsigned int	*k;

	i = 0;
	j = j - 1;
	tmp = ft_strnew(13);
	if (wc <= 127)
		return (1);
	tmp = ft_dectobin(wc);
	tmp = ft_unimask(tmp, ft_strlen(tmp));
	k = ft_split_int_etoile(tmp);
	i = 0;
	while (k[i] > 0)
	{
		k[i] = ft_bintodec(k[i]);
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:18:16 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/21 15:07:28 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_max_plus_ascii(int i)
{
	if (i > 127)
		while (i > 127)
			i = 127 - 255 + (i - 127) - 1;
	if (i < -128)
		while (i < -128)
			i = 127 + 255 + (i - 127) + 1;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:57:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 15:18:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "libftprintf.h"

int		ft_print_d_plus(va_list ap, char **aff)
{
	int d;

	d = va_arg(ap, int);
	if (d >= 0)
	{
		*aff = ft_strjoin(*aff, "+");
		*aff = ft_strjoin(*aff, ft_itoa(d));
		return (0);
	}
	else
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

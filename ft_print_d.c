/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 15:17:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_d(va_list ap, char *s, int i, char **aff)
{
	int d;
	char *tmp;
	size_t j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp[j] = s[i];
		i--;
		j++;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	d = va_arg(ap, int);
	while (j > (ft_strlen(ft_itoa(d))))
	{
		*aff = ft_strjoin(*aff, " ");
		j--;
	}
	*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

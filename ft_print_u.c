/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/31 19:13:31 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_u(va_list ap, char *s, int i)
{
	unsigned int d;
	char *tmp;
	unsigned int j;

	j = 0;
	tmp = ft_strnew(13); // modif longueur unsigned int
	while (s[i] > '0' && s[i] <= '9')
	{
		tmp[j] = s[i];
		i--;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi((const char *)tmp);
	d = va_arg(ap, unsigned int);
	while (j >= d) // atoi unsigned int
	{
		ft_putchar (' ');
		j--;
	}
	ft_putnbr((int)d); //putnbr unsigned int
	return (ft_strlen(ft_itoa((int)d)) + ft_atoi(tmp)); //itoa unsigned int
}

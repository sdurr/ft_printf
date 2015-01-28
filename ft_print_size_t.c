/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/20 15:33:20 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int			ft_print_size_t(va_list ap, char *s, int i, char **aff)
{
	size_t		d;
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = ft_strnew(13);
	j = i;
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	d = va_arg(ap, int);
	if ((s[i] == '.' && s[i + 1] == '0' && s[i - 1] == '%')
		|| (s[i] == '.' && d == 0))
		return (0);
	if (s[i] == ' ' && j == 0)
		*aff = ft_strjoin(*aff, " ");
	ft_number_befor(ft_strlen(d), s, i, aff);
	if (s[i] == '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	if (s[i] != '-')
		*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:57:26 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int				ft_space_number(char *s, int i, char **aff)
{
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	if (s[i] == '.')
		i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	while (j-- > 1)
	{
		if (s[i + 1] != '0')
			*aff = ft_strjoin(*aff, " ");
		else
			*aff = ft_strjoin(*aff, "0");
	}
	if (s[i] == '-')
		return (0);
	return (-1);
}

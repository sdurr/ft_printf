/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 15:27:31 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_print_c(va_list ap, char *s, int i, char **aff)
{
	char c;
	char *tmp;
	int j;
	char *tmp2;

	tmp2 = ft_strnew(2);
	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] > '0' && s[i] <= '9')
	{
		tmp[j++] = s[i];
		i--;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	c = (char)va_arg(ap, int);
	while (j > 1)
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
	if (c == 0)
		return (1);
	tmp2[0] = c;
	*aff = ft_strjoin(*aff, tmp2);
	return (0);
}

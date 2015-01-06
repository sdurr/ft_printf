/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 15:17:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include "libftprintf.h"

int	ft_print_c_maj(va_list ap, char *s, int i, char **aff)
{
	wchar_t c;
	char *tmp;
	int j;
	char *tmp2;
	tmp2 = ft_strnew(2);
	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
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
	tmp2[0] = (char)c;
	*aff = ft_strjoin(*aff, tmp2);
	return (0);
}

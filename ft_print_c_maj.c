/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 17:41:17 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>

int	ft_print_c_maj(va_list ap, char *s, int i, char **aff)
{
	wchar_t c;
	char *tmp;
	int j;
	wchar_t *tmp2;

	tmp2 = (wchar_t *)ft_strnew(2);
	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	c = va_arg(ap, wchar_t);
	while (j-- > 1)
		*aff = ft_strjoin (*aff, " ");
	if (c == 0)
		return (1);
	tmp2[0] = c;
	*aff = ft_strjoin(*aff, (char *)tmp2);
	return (0);
}

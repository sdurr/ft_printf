/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/12 09:04:56 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int				ft_print_c(va_list ap, char *s, int i, char **aff)
{
	char		c;
	char		*tmp;
	int			j;
	char		*tmp2;

	tmp2 = ft_strnew(2);
	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	c = (char)va_arg(ap, int);
	if ((c == 0 && j == 0 && s[i] != ' ' && s[i + 1] != '0')|| (c == 0 && s[i] == '.'))
			return (1);
	if (s[i + 1] == '0')
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
		while (j-- > 0)
	{
		if (s[i + 1] != '0')
			*aff = ft_strjoin (*aff, " ");
		else
			*aff = ft_strjoin (*aff, "0");
	}
	if (s[i] == ' ' && c == 0)
		*aff = ft_strjoin (*aff, " ");
	if (tmp[0] != '\0' || (s[i] == ' ' && c == 0) || (s[i + 1] == '0' && c == 0))
		return (-2);
	tmp2[0] = c;
	*aff = ft_strjoin(*aff, tmp2);
	if (c == 0)
		return (1);
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/08 15:12:49 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int		ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i] == '.')
	{
		i--;
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		if (j > stop)
			while (j-- >= 1)
			{
				*aff = ft_strjoin(*aff, " ");
				if (j == stop)
					return (0);
			}
	}
	return (0);
}

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
	if (c == 0)
		return (1);
	ft_point_space(s, i, aff, j);
	while (j-- > 1)
		*aff = ft_strjoin (*aff, " ");
	tmp2[0] = c;
	*aff = ft_strjoin(*aff, tmp2);
	return (0);
}

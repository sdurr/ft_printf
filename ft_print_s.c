/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/08 12:23:55 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int ft_point_space(char *s1, char *s, int i, char **aff)
{
	size_t j;
	char *tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i] == '.')
	{
		i--;
		while (s[i] >= '0' && s[i] <= '9')
		{
			tmp[j] = s[i];
			i--;
			j++;
		}
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
			while (j-- > (ft_strlen(s1)))
				*aff = ft_strjoin(*aff, " ");
	}
	return (0);
}

int	ft_print_s(va_list ap, char *s, int i, char **aff)
{
	char *s1;
	char *tmp;
	size_t j;

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
	s1 = va_arg(ap, char *);
	ft_point_space(s1, s, i, aff);
	if (!s1 || !ap)
	{
		*aff = ft_strjoin(*aff, "(null)");
		return (0);
	}
	while (j > ft_strlen(s1))
	{
		if (s[i] != '.')
			*aff = ft_strjoin (*aff, " ");
		j--;
	}
	*aff =	ft_strjoin(*aff, s1);
	return (0);
}

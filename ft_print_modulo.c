/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 10:06:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int ft_point_space(char *s, int i, char **aff)
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
			while (j-- > 1)
			{
				if (s[i + 1] != '0')
					*aff = ft_strjoin(*aff, " ");
				else
					*aff = ft_strjoin(*aff, "0");
			}
	}
	return (0);
}

int	ft_print_modulo(char *s, int i, char **aff)
{
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
	ft_point_space(s, i, aff);
	if (s[i] != '.')
		while (j-- > 1)
		{
			if (s[i - 1] != '0')
			*aff = ft_strjoin(*aff, " ");
			else
				*aff = ft_strjoin(*aff, "0");
		}
	tmp = ft_strdup("%");
	*aff =	ft_strjoin(*aff, tmp);
	return (0);
}

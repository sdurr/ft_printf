/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:24:17 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

static int		ft_point_space(char *s1, char *s, int *i, char **aff)
{
	size_t		j;
	char		*tmp;
	int			test;

	j = 0;
	test = 0;
	if (s[i[2]--] == '.' && (tmp = ft_strnew(13)))
	{
		while (s[i[2]] >= '0' && s[i[2]] <= '9')
			tmp[j++] = s[i[2]--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		test = j;
		if (s1)
		{
			if (i[0] == 0)
				while (j--)
					*aff = ft_strjoin(*aff, " ");
			else
				while (j-- > ft_strlen(s1))
					*aff = ft_strjoin(*aff, " ");
		}
		else
			while (j--)
				(s[i[2] + 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
					: (*aff = ft_strjoin(*aff, "0"));
	}
	return (test);
}

static void		ft_suite(size_t j, char **aff, char *s, int i)
{
	while (j--)
		(s[i - 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
			: (*aff = ft_strjoin(*aff, "0"));
}

int				ft_print_s(char *s1, char *s, int i, char **aff)
{
	char		*tmp;
	int			k[4];

	k[0] = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[k[0]++] = s[i--];
	tmp = ft_revers(tmp);
	k[0] = ft_atoi(tmp);
	k[1] = k[0];
	k[2] = i;
	k[3] = ft_point_space(s1, s, k, aff);
	if ((!s1 && k[3] == 0 && (*aff = ft_strjoin(*aff, "(null)"))))
		return (0);
	if (s1)
	{
		while (k[0] > (int)ft_strlen(s1))
		{
			if (s[i] != '.')
				(s[i + 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
					: (*aff = ft_strjoin(*aff, "0"));
			k[0]--;
		}
		if (k[3] > 0 && k[1] == 0 && s[i] == '.')
			return (0);
		*aff = ft_strjoin(*aff, s1);
	}
	else
		ft_suite(k[0], aff, s, i);
	return (0);
}

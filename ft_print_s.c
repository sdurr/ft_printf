/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/02 15:47:14 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

static int		ft_point_space(char *s1, char *s, int i, char **aff)
{
	size_t		j;
	char		*tmp;
	int			test;

	j = 0;
	if (s[i--] == '.' && (tmp = ft_strnew(13)))
	{
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		if ((test = j) && s1)
			while (j-- > (ft_strlen(s1)))
				*aff = ft_strjoin(*aff, " ");
		else
			while (j--)
				(s[i + 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
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
	size_t		j;
	int			test;

	j = 0;
	if ((tmp = ft_strnew(13)) && (i--))
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	test = ft_point_space(s1, s, i, aff);
	if ((!s1 && test == 0 && (*aff = ft_strjoin(*aff, "(null)"))))
		return (0);
	if (s1)
	{
		while (j > ft_strlen(s1))
		{
			if (s[i] != '.')
				(s[i + 1] != '0') ? (*aff = ft_strjoin(*aff, " "))
					: (*aff = ft_strjoin(*aff, "0"));
			j--;
		}
		*aff = ft_strjoin(*aff, s1);
	}
	else
		ft_suite(j, aff, s, i);
	return (0);
}

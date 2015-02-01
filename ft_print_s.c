/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/28 13:42:27 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

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
			{
				if (s[i + 1] != '0')
					*aff = ft_strjoin(*aff, " ");
				else
					*aff = ft_strjoin(*aff, "0");
			}
	}
	return (test);
}

int				ft_print_s(va_list ap, char *s, int i, char **aff)
{
	char		*s1;
	char		*tmp;
	size_t		j;
	int			test;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	s1 = va_arg(ap, char *);
	test = ft_point_space(s1, s, i, aff);
	if ((!s1 && test == 0) || (!ap && test == 0))
	{
		*aff = ft_strjoin(*aff, "(null)");
		return (0);
	}
	if (s1)
		while (j > ft_strlen(s1))
		{
			if (s[i] != '.')
				*aff = ft_strjoin (*aff, " ");
			j--;
		}
	else
		while (j--)
		{
			if (s[i - 1] != '0')
				*aff = ft_strjoin(*aff, " ");
			else
				*aff = ft_strjoin(*aff, "0");
		}
	if (s1)
		*aff = ft_strjoin(*aff, s1);
	return (0);
}

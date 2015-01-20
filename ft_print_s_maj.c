/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/20 15:31:33 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
/*
static int		ft_point_space(wchar_t *s1, char *s, int i)
{
	size_t		j;
	char		*tmp;
	int			ret;

	tmp = ft_strnew(13);
	j = 0;
	ret = 0;
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
			while (j > (ft_wstrlen(s1)))
			{
				ft_putstr(" ");
				ret++;
				j--;
			}
	}
	return (ret);
}
*/
int	ft_print_s_maj(va_list ap, char *s, int i)
{
	wchar_t *s1;
	char *tmp;
	size_t j;
	int ret;

	j = 0;
	ret = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp[j++] = s[i];
		i--;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
 	s1 = va_arg(ap, wchar_t *);
	//ret += ft_point_space(s1, s, i);
	if (!s1 || !ap)
	{
		ft_putstr("(null)");
		return (6);
	}
/*	while (j > ft_wstrlen(s1))
	{
		if (s[i] != '.')
		{
			ft_putstr(" ");
			ret++;
		}
		j--;
		}*/
	i = 0;
	while (i < 6)
	{
	ft_calc_and_print_wchar(*s1, j, tmp);
	s1++;
	tmp = ft_strnew(13);
	j = 0;
	i++;
	}
		ft_putstr("test");
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 18:58:21 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

static int		ft_point_space(char *s, int i, char **aff, size_t stop)
{
	size_t		j;
	char		*tmp;

	tmp = ft_strnew(13);
	j = 0;
	if (s[i--] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
			tmp[j++] = s[i--];
		tmp = ft_revers(tmp);
		j = ft_atoi(tmp);
		while (j-- >= stop)
			(s[i + 1] == '0') ? (*aff = ft_strjoin(*aff, "0"))
				: (*aff = ft_strjoin(*aff, " "));
	}
	if (s[i + 1] == '0')
		return (-2);
	return (0);
}

int				ft_print_s_maj(va_list ap, char *s, size_t i)
{
	wchar_t		*s1;
	char		*tmp;
	size_t		j;
	int			ret;
	size_t		prec;

	j = 0;
	ret = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if (!(s1 = va_arg(ap, wchar_t *)) || !s1 || !ap)
	{
		ft_putstr("(null)");
		return (6);
	}
	prec = 0;
	ret = 0;
	tmp = ft_strnew(13);
	while (s1[ret] && prec <= j)
	{
		prec += ft_calc_wstr(s1[ret], j, tmp);
		ret++;
	}
	tmp = ft_strnew(13);
	if ((ft_point_space(s, i, &tmp, ret)) == -2)
	{
		ret = 0;
		ft_putstr(tmp);
		ret += ft_strlen(tmp);
		return (ret);
	}
	prec = ret - 1;
	ret = 0;
	ft_putstr(tmp);
	ret += ft_strlen(tmp);
	tmp = ft_strnew(13);
	i = 0;
	while (s1[i])
	{
		ret += ft_calc_and_print_wchar(s1[i], tmp);
		i++;
		tmp = ft_strnew(13);
		if (i >= prec && j > 0)
			return (ret);
	}
	free(tmp);
	return (ret);
}

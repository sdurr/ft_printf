/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:28 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 10:08:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_d(va_list ap, char *s, int i, char **aff)
{
	int d;
	char *tmp;
	size_t j;
	size_t point;

	j = 0;
	tmp = ft_strnew(13);
	i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp[j] = s[i];
		i--;
		j++;
	}
	tmp = ft_revers(tmp);
	j = ft_atoi(tmp);
	if (s[i] == '.' && s[i + 1] == '0')
		return (0);
	d = va_arg(ap, int);
	if (s[i] == ' ' && j == 0 && d >= 0)
			*aff = ft_strjoin(*aff, " ");
	point = 0;
	tmp = ft_strnew(13);
	if (s[i] == '.')
		i--;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp[point] = s[i];
		i--;
		point++;
	}
	tmp = ft_revers(tmp);
	point = ft_atoi(tmp);
	while (point  > (ft_strlen(ft_itoa(d))))
	{
		*aff = ft_strjoin(*aff, " ");
		point--;
		while (s[i] != '.' && s[i])
			i++;
	}
	while (j > (ft_strlen(ft_itoa(d))))
	{
		if (s[i] == '.')
			*aff = ft_strjoin(*aff, "0");
		else
			*aff = ft_strjoin(*aff, " ");
		j--;
	}
	*aff = ft_strjoin(*aff, ft_itoa(d));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 12:43:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

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
	while (j > ft_strlen(s1))
	{
		*aff = ft_strjoin (*aff, " ");
		j--;
	}
	*aff =	ft_strjoin(*aff, s1);
	if (ft_strlen(s1) >= (size_t)ft_atoi(tmp))
		return (ft_strlen(s1));
	return (ft_atoi(tmp));
}
